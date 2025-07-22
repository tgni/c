#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int main()
{
	uint32_t a, b;

	a = 1; b = 2;
	printf("a: %d b: %d, a-b: %d b-a: %d abs(a-b): %d, abs(b-a): %d\n", a, b, a-b, b-a, abs(a-b), abs(b-a));

	return 0;
}
