/* File: test_pointer.c */
#include <stdio.h>

typedef struct task_s {
        int a;
        int b;
        int c;
        int d;
        struct task_s *sp;
        struct task_s *_sp;
} task_t;

int main(void)
{
        int size;
        task_t *sp, *_sp;
        task_t stack[1024];

        sp = &stack[0];
        _sp = &stack[1023];
        size = _sp - sp;    

        printf("sp:%p  _sp:%p\n", sp, _sp);

        printf("%d\n", size);

        return 0;
}
