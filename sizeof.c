#include <stdio.h>

#define printf_s printf

int main()
{
	printf_s("sizeof(1.1) %d sizeof(1.1f) %d sizeof(1.1l) %d\n", sizeof(1.1), sizeof(1.1f), sizeof(1.1l));
	printf_s("sizeof(1.1F) %d sizeof(1.1L) %d\n", sizeof(1.1F), sizeof(1.1L));
	printf_s("sizeof(1) %d sizeof(1l) %d sizeof(1ll) %d\n", sizeof(1), sizeof(1l), sizeof(1ll));
	printf_s("sizeof(1L) %d sizeof(1LL) %d\n", sizeof(1L), sizeof(1LL));
	printf_s("sizeof(0xFF) %d sizeof(0xFFu) %d\n", sizeof(0xFF), sizeof(0xFFu));
	printf_s("sizeof(0xFFFFFFFFFFFFFFFFLL) %d sizeof(0xFFFFFFFFFFFFFFFF) %d\n", sizeof(0xFFFFFFFFFFFFFFFFLL), sizeof(0xFFFFFFFFFFFFFFFF));
	printf_s("sizeof(int) %d sizeof(long) %d sizeof(long long) %d sizeof(float) %d sizeof(double) %d sizeof(long double) %d\n",
		  sizeof(int), sizeof(long), sizeof(long long), sizeof(float), sizeof(double), sizeof(long double));
	printf_s("sizeof(long int) %d sizeof(long long int) %d", 
		  sizeof(long int), sizeof(long long int));

	if (-2 + 1u >= 0)
		printf_s("-2+1u >= 0\n");
	else
		printf_s("-2+1u < 0\n");

	if (-2 + 1 >= 0)
		printf_s("-2+1 >= 0\n");
	else
		printf_s("-2+1 < 0\n");

    return 0;
}
