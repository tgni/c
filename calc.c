#include <stdio.h>

int main()
{
	int i, sum = 0;
	for (i = 1; i <= 125; ++i) {
		sum += i * (i + 1);
	}
	printf("sum: %d\n", sum);

	return 0;
}
