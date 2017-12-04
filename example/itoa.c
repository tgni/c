/* File: itoa.c */
#include <stdio.h>
#include <math.h>
#include <string.h>

void reverse(char s[])
{
	int i, j, c;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];	
		s[i] = s[j];
		s[j] = c;
	}
}

/*
void itoa(int n, char s[])
{
	int i, sign, flag = 0;

	if ((sign = n) < 0) {
		if (n == -pow(2, 31)) {
			n = n + 1;	
			flag = 1;
		}
		n = -n;
	}
	
	i = 0;
	do {
		s[i++] = n % 10 + '0';	
	} while (( n /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';	
	}
	if (flag)
		s[0]++;	

	s[i] = '\0';
	reverse(s);
}*/

void itoa(int n, char s[], int width)
{
	int i, j, sign, flag = 0;

	if ((sign = n) < 0) {
		if (n == -pow(2, 31)) {
			n = n + 1;	
			flag = 1;
		}
		n = -n;
	}
	
	i = 0;
	j = 0;
	do {
		s[i++] = n % 10 + '0';	
		j++;
	} while (( n /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';	
	}
	
	while (j < width) {
		s[j++] = ' ';
	}
	if (flag)
		s[0]++;	

	s[j] = '\0';
	reverse(s);
}

/*
 * normal bases is already known as 2, 8, 10, 16, 
 * other base such as 10 ~ 16 we use character 'A' ~ 'F',
 * consequently, base bigger than 16, should as 'G' ~ 'Z',
 * biggest base as 'Z', which means base 35.
 */
void itob(int n, char s[], int b)
{
	int i, tmp, sign, flag = 0;

	if (b > ('Z' - 'A' + 10)) {
		printf("invalid base\n");
		return;
	}
	if ((sign = n) < 0) {
		if (n == -pow(2, 31)) {
			n = n + 1;	
			flag = 1;
		}
		n = -n;
	}
	i = 0;
	do {
		tmp = n % b;
		if (tmp < 10) {
			s[i++] = tmp + '0';
		} else {
			s[i++] = tmp + 55;	
		}
	} while (( n /= b) > 0);

	if (sign < 0) {
		s[i++] = '-';	
	}
	if (flag)
		s[0]++;	

	s[i] = '\0';
	reverse(s);
}

main()
{
	int n;
	char s[128];

	//n = -pow(2, 31);
	n = 31;
	printf("%8d\n", n);
	//itob(n, s, 15);
	itoa(n, s, 8);
	printf("%s\n", s);

	return;
}
