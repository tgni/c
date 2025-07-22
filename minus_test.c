#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;

	printf("a %d b %d c %d\n", a, b, c);
	c -= a - b;
	printf("c -= a - b: %d\n", c);
	c = c - a - b;
	printf("c = c - a - b: %d\n", c);

	return 0;
}
