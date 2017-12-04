#include <ctype.h>
#include <stdio.h>
#include <math.h>

extern int getch(void);
extern void ungetch(int c);

/* get next integer from input into *pn */
int getfloat(float *pn)
{
	int c, sign, p; /* p means power of deimal */
	float decimal;

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
			ungetch(c);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + c - '0';
	if (c == '.') {
		c = getch();
		p = 0;
	}
	for (decimal = 0; isdigit(c); c = getch()) {
		decimal = 10 * decimal + c - '0';
		p++;
	}
	decimal /= pow(10, p);
	*pn += decimal;
	if (c != EOF)
		ungetch(c);
	return c;
}


main()
{
	float i;

	getfloat(&i);
	printf("%f\n", i);

	return 0;
}
