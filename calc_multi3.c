#include "stdio.h"

int main()
{
	int i, j, k, l;
	int nr = 0;

	for (i = 0; i < 10; ++i) {
		for (j = i + 1; j < 10; ++j) {
			for (k = j + 1; k < 10; ++k) {
				for (l = k + 1; l < 10; ++l) {
					if ((i+j+k+l) % 3 == 0) {
						printf("%d+%d+%d+%d = %d\n", i, j, k, l, i+j+k+l);
						++nr;
					}
				}
			}
		}
	}
	printf("total : %d\n", nr);

	return 0;
}
