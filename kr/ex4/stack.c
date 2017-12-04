#include <stdio.h>

#define  MAXVAL		(100)

static int sp = 0;
static double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;	
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];	//take care ++ and -- position
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double top(void)
{
	if (sp > 0)
		return val[sp - 1];
	else {
		printf("error: stack empty\n");	
		return 0.0;
	}
}

void clear()
{
	sp = 0;
}

void swaptop()
{
	double a, b;

	a = pop();
	b = pop();

	push(a);
	push(b);
}


main()
{
	double n;

	push(1);
	push(2);
	printf("%g \n", top());
	swaptop();
	printf("%g \n", top());
	clear();
	printf("%g \n", top());

	return 0;
}
