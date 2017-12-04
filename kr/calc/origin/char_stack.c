#include <stdio.h>
#include "calc.h"

static int sp = 0;
static int val[MAXVAL];

void push_char(int c)
{
	if (sp < MAXVAL)
		val[sp++] = c;	
	else
		printf("error: stack full, can't push %c\n", c);
}

int pop_char(void)
{
	if (sp > 0)
		return val[--sp];	//take care ++ and -- position
	else {
		//printf("error: stack empty\n");
		return -1;
	}
}

int top_char(void)
{
	if (sp > 0)
		return val[sp - 1];
	else {
		//printf("error: stack empty\n");	
		return -1;
	}
}
