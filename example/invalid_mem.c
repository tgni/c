/* File: invalid_mem.c */
#include <stdio.h>
int invalid_mem(int size, unsigned char *mac_list)
{
        int i;
        unsigned char *p;
        p = mac_list;
        for (i = 0; i < size; i++, p++) {
                printf("addr: %lu ", p);
                printf("value: %lu \n", *p);
        }
        return 0;
}

int main(void)
{
        unsigned char test[5] = {0, 1, 2, 3, 4};
        invalid_mem(100, test);
        return 0;
}
