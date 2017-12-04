#ifndef __STACK_H__
#define __STACK_H__

struct stack_s;
typedef struct stack_s stack_t;

extern int is_empty(stack_t *s);
extern int is_full(stack_t *s);
stack_t *create_stack(int esz, int nr);
void dispose_stack(stack_t *s);
void make_empty(stack_t *s);
void push(stack_t *s, void *obj);
void *pop(stack_t *s);
void *top(stack_t *s);

#endif /* __STACK_H__ */
