#include <stdio.h>
/* hello my new program */
char *strncpy(char *dest, const char *src, size_t n)
{
	char *p; 

	for (p = dest; 0 < n && *src != '\0'; --n)
		*dest++ = *src++;
	for ( ; 0 < n; --n)
		*dest++ = '\0';

	return p;
}

char *strncat(char *dest, const char *src, size_t n)
{
	char *p;

	for (p = dest; *p != '\0'; ++p)
		;
	for ( ; 0 < n && *src != '\0'; --n)
		*p++ = *src++;
	*p = '\0';

	return (dest);
}

int strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

//int strncmp(const char *s, const char *t, size_t n)
int strncmp(const char *s, const char *t, int n)
{
	for ( ; *s == *t; s++, t++)
		if (--n <= 0)
			return 0;
	return *s - *t;
}

main()
{
	char s[32];
	char t[32] = "world";
	char *p;

	p = strncpy(s, t, 7);
	printf("strncpy: %s\n", p);
	
	char r[32] = "hello ";
	p = strncat(r, t, 10);
	printf("strncat: %s\n", p);

	char o[32] = "world";
	int res = strncmp(o, t, 0);
	printf("strncmp:%d\n", res);

}
