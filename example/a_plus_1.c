/* File: a_plus_1.c */
#include <stdio.h>
int main(void)
{
	char a = 1;
	char b = a + 1;
	char c = -~a;
	char d = -1;
	char e = 0x80;
	printf("b:%x, c:%x, d:%x, e:%d", b, c, d, e);
	return 0;
}
