#include <ctype.h>
#include <stdio.h>

extern int getch(void);
extern void ungetch(int c);

/* get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))	
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	
		return 0;
	}
	sign = c == '-' ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + c - '0';
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

main()
{
	int i;

	getint(&i);
	printf("%d\n", i);

	return 0;
}
