#include <stdio.h>

int main(void)
{
	int array[10] = {1, 2};	
	int i;

	for (i = 0; i < 10; ++i)
		printf("array[%d]: %d\n", i, array[i]);

	return 0;
}
