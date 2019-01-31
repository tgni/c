/* File: privilege.c */
#include <stdio.h>
int main()
{
        unsigned char a[10] = {5, 10, 15, 4, 5, 6, 7, 8, 9, 10};
        unsigned char *p = NULL;
        unsigned char x, y, z;
        p = a;
        x = (*p++);
        y = (*p++);
        z = (*p++);
        printf(" x: %d y: %d z: %d\n", x, y, z);
        return 0;
}
