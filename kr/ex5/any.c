#include <stdio.h>

/* the same job as strpbrk, only different return value */
int any(char *s1, char *s2)
{
	int pos = 0;

	while (*s1++ != *s2)
		++pos;

	if (!pos)
		return -1;

	while (*s1++ == *++s2)
		;

	if (*s2 != '\0')
		return -1;

	return pos;
}

main()
{
	char s1[] = "hello world! I love you!";
	char s2[] = "world! I love";
	char s3[] = "world I love";

	printf("s1 contain s2? : %d \n", any(s1, s2));
	printf("s1 contain s3? : %d \n", any(s1, s3));

	return;
}
