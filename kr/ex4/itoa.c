#include <stdio.h>

/* 
 * Use unsigned m instead of original n, to solve
 * max minus number problem 
 */

char *__itoa(unsigned n, char s[])
{
	if (n / 10)
		s = __itoa(n / 10, s);	

	*s++ = n % 10 + '0';
	*s   = '\0';
}

char *itoa(int n, char s[])
{
	unsigned int m;
	if (n < 0) {
		*s++ = '-';
		m = -n;
	}
	return __itoa(m, s);
}

main()
{
	int i = -pow(2, 31);
	char s[100];

	printf("%i\n", i);
	itoa(i, s);
	printf("%s\n", s);
	
	int j = -2345;
	itoa(j, s);

	printf("%s\n", s);
}
