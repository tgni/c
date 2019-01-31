#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "defs.inc"

static char buf[1024];
static u32 counter = 0;

void initbuf(void)
{
        counter = 0;
        memset(buf, 0, 1024);
}

void Hex2Str(u32 N)
{
        if (N >= 2) {
                Hex2Str(N/2);
        }
        if((counter >= 8) && ((counter+1) % 9 == 0))
                buf[counter++] = 0x20;
        //buf[counter++] = 0x30 + (N%2);
        buf[counter++] = (N%2);

}

//calculate N's length
s32 CalN(u32 N)
{
        s32 cc = 1;
        while(N/2){
                cc++; 
                N /= 2;
        }
        return cc;
}

void Putbits(u32 N, u32 length)
{
        s32 index,Nlen;
        Nlen = CalN(N);
        index = length - Nlen;
        if(length > Nlen)
                while(index--) Hex2Str(0); 
        Hex2Str(N); 
}

s32 main(void)
{
        u32 tmp = 0x99;
        u32 tmp1 = 0x0;
        u32 tmp2 = 0xaaaa;
        u32 i = 0;

        //we should initbuf before use Putbits. Max Putbits equals 128
        initbuf();
        Putbits(tmp,128);
        Putbits(tmp1,32);
        Putbits(tmp2,24);
        Putbits(0x1,1);
        Putbits(0x2,2);
        //write buf to file
        //ignored
        printf("buf:%s\r\n",buf);
        FILE *fp = NULL;
        if ((fp  = fopen("test.h264","wb"))==NULL)
                printf("can't open file test.h264\n");

        fwrite(buf,counter,1,fp);
        fclose(fp);

        return 0;
}
