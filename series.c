#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j, n;

	if (argc != 2) {
		printf("Usage: ./test <Num>\n");
		return -1;
	}

	n = strtoul(argv[1], NULL, 0);

	for (i = 0; i < n; ++i)
		for (j = i; j > 0; --j)
			printf("%d ", i);
	printf("\n");

	return 0;
}
