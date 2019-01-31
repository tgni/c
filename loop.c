/* File: loop.c */
#include <stdio.h>
int main(void)
{
        int i = 0;
        for (i = 0; i < 10; ++i) {
                printf("i: %d\r\n", i);
                continue; 
        }
        return 0;
}
