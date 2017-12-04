#include <stdio.h>
#include "calc.h"

static int sp = 0;
static double val[MAXVAL];

void push_num(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;	
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop_num(void)
{
	if (sp > 0)
		return val[--sp];	//take care ++ and -- position
	else {
		//printf("error: stack empty\n");
		return 0.0;
	}
}

double top_num(void)
{
	if (sp > 0)
		return val[sp - 1];
	else {
		//printf("error: stack empty\n");	
		return 0.0;
	}
}
