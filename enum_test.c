#include <stdio.h>

enum {
	A,
	B = A,
	C = B,
	D,
};

int main()
{
	printf("%d %d %d %d\n", A,B,C,D);
	return 0;
}

