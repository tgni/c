#include <stdio.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, char *t)
{
	while (*s++)
		;
	s--;
	while (*s++ = *t++)
		;
}

#if 0
void _strcat(char *s, char *t)
{
	while (*++s)
		;
	/* when s is "", it skip the first '\0', s wont get the right answer */
	while (*s++ = *t++)
		;
}
#endif

main()
{
	void strcat(char *s, char *t);
	char s[128] = "hello";
	char t[32] = " world";

	strcat(s, t);
	printf("%s\n", s);

	return;
}
