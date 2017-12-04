/* File: macro.c */
#include <stdio.h>
#if 1

#else
#    error "Build Properties, testing error happens!"
#endif
int main(void)
{
        printf("hello world!\n");
}
