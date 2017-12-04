/* File: stack_mem.c */
#include <stdio.h>
char *stackmem(void)
{
        char p[100] = "hello world!\r\n";
        return p;
}
#if 0
char *stackmem(void)
{
        char p[100];
        strcpy(p, "hello world \r\n");
        return p;
}
char *stackmem(void)
{
        char p[100];
        p[0] = 'h';
        p[1] = 'e';
        p[2] = 'l';
        p[3] = 'l';
        p[4] = 'o';
        p[5] = ' ';
        p[6] = '\n';
        p[7] = '\0';
        return p;
}
#endif
int main(void)
{
        char *str = NULL;
        str = stackmem();
        printf("%s", str);
        return 0;
}
