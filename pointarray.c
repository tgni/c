/* File: pointarray.c */
#include <stdio.h>
int main()
{
	int b[15] = {1, 2, 3, 4, 5};
	int *p;

	p = (void *)b + 1;
	printf("b[1]: %p p: %p\n", &b[1], p);

        return 0;

}
