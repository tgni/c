#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

#define MIN_STACK_SZ	(5)
#define EMPTY_TOS	(-1)

struct stack_s {
	int cap;	//capacity
	int sp;		//position
	int esz;	//element size
	void *array;
};

stack_t *create_stack(int esz, int nr)
{
	stack_t *s;

	if (nr < MIN_STACK_SZ) {
		printf("error: stack size too small!\n");
		return NULL;
	}

	s = malloc(sizeof(stack_t));
	if (!s) {
		printf("out of memory!\n");
		return NULL;	
	}

	s->array = malloc(esz * nr);
	if (!s->array) {
		printf("out of array memory!\n");	
		return NULL;
	}
	s->cap = nr;
	s->esz = esz;
	make_empty(s);

	return s;
}

void dispose_stack(stack_t *s)
{
	if (s) {
		free(s);	
		free(s->array);
	}
}

int is_full(stack_t *s)
{
	return s->sp >= s->cap;
}

int is_empty(stack_t *s)
{
	return s->sp == EMPTY_TOS;
}

void make_empty(stack_t *s) 
{
	s->sp = EMPTY_TOS;
}

void push(stack_t *s, void *obj)
{
	if (is_full(s)) {
		printf("error: full stack\n");
	} else {
		memcpy((void *)(s->array + (++s->sp)*s->esz), obj, s->esz);
	}
}

void *pop(stack_t *s)
{
	if (!is_empty(s))
		return (void *)(s->array + (s->sp--)*s->esz);
	return NULL;
}

void *top(stack_t *s)
{
	if (!is_empty(s))
		return (void *)(s->array + s->sp*s->esz);
	return NULL;
}
