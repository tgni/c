/* File: array.c */
#include <stdio.h>
int main(void)
{
	int a[12][31];
	int b, c, d;
	
	a[4][0] = 2;
	a[4][7] = 1;
	b = *(a[4] + 7);
	c = *(*(a + 4) + 7);
	d = *a[4] + 7;

	printf("b: %d c: %d, d: %d\n", b, c, d);

	return 0;
}
