#include<stdio.h>

int main(void)
{
	int i;

	for (i = 0; i < 5; ++i) {
		//break;
		continue;
	}

	printf("i = %d\n", i);
}
