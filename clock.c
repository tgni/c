#include <stdio.h>
#include <time.h>
#include "types.h"

main(void)
{
	clock_t c;
	int32_t i;

	for (i = 0; i < 10000000; ++i)
		;

	c = clock();
	printf("clock: %-10u\n", c);

	return;
}
