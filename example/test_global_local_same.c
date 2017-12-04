/* File: test_global_local_same.c */
#include <stdio.h>

int p = 100;

int set_var(int *p)
{
        p = p;

        return 0;
}

int main(void)
{
        int *q, a = 10;
        q = &a;
        set_var(q);
        printf("%c", p);

        return 0;
}
