/* File: in2out.c */
#include <stdio.h>
main()
{
        int c;
        c = getchar();
        while (c != EOF) {
                putchar(c); 
                c = getchar();
        }
}
