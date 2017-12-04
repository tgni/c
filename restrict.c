#include <stdio.h>
#include <stdlib.h>

int * __restrict ptr;
int * __restrict ptr2;

int main(void)
{
	ptr2 = ptr = malloc(sizeof(int));

	free(ptr2);

	return 0;
}
