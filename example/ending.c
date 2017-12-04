/* File: ending.c */
#include <stdio.h>
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
union ending_u {
        uint32_t a;
        uint8_t  b;
}u;
int main(void)
{
       u.a = 0x12345678;
       printf("u.a = %x\n",u.a);
       printf("u.b = %x\n",u.b);

       if (u.b == 0x12) {
                printf("machine is big ending\n"); 
       } else if (u.b == 0x78) {
                printf("machine is little ending\n"); 
       }

       return 0;
}
