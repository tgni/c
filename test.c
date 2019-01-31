#include <stdio.h>

void main(void)
{
	float a = 0.5;
	float b = 1.5;
	float c = -12.5;
	float d = -8.25;

	unsigned int *pa = NULL;
	pa = (unsigned int *)&a;
	
	unsigned int *pb = NULL;
	pb = (unsigned int *)&b;

	unsigned int *pc = NULL;
	pc = (unsigned int *)&c;

	unsigned int *pd = NULL;
	pd = (unsigned int *)&d;

	printf("a: %08x b: %08x c: %08x d: %08x\n", *pa, *pb, *pc, *pd);

	return;
}
