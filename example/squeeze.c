/* File: squeeze.c */
/* 
 * File: squeeze.c
 * Description:
 *	simulate xor of string s1 and s2:
 *	if s1[i] == s2[i], delete it from s1
 * History:
 *	Jan 8, 2016	Tgni	Create
 */
#include <stdio.h>

int isfind(char s[], char c) 
{
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == c) {
			return 1;
		}
	}
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j;

	for (i = j = 0; s1[i] != '\0'; i++) {
		if (!isfind(s2, s1[i])) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}

main()
{
#if 0
	/* Take Care! 
	 * string literal, cannot be changed!
	 * we can never use pointer to allocate memory
	 * except string literal, even it does, string
	 * literal still cannot be change.
	 */
	char *s1 = "hI, beautiful world";
	char *s2 = "hello world";
#else
	char s1[] = "hI, beautiful world";
	char s2[] = "hello world";
#endif
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	squeeze(s1, s2);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	return;
}
