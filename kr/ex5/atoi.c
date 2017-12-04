#include <stdio.h>
int atoi(char *s)
{
	int c, sign, num;

	while (isspace(*s))
		s++;

	if (!isdigit(c = *s) && c != '\0' && c != '+' && c != '-')
		return ~0;

	sign = c == '-' ? -1 : 1;
	if (c == '+' || c == '-') {
		if (!isdigit(*++s))
			return ~0;
	}

	for (num = 0; isdigit(*s); s++)
		num = 10 * num + *s - '0';
	num *= sign;

	if (*s != '\0')
		return ~0;

	return num;
}

int itoa(int i)
{
/* omitted */
}

main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("usage: ./test 'integer string'\n");
		return;
	}
	printf("%s: %d\n", argv[1], atoi(argv[1]));
}
