#include <stdio.h>

/* check t occurs at the end of s */
int strend(char *s, char *t)
{
	while (*s++ != *t)
		;
	s--;
	while (*s++ == *t++) {
		if (*s == '\0' && *t == '\0')
			return 1;
	}
	return 0;
}

main()
{
	char s[] = "hello world! I love you!";
	char t0[] = "hello world! I love you!";
	char t1[] = "world! I love you!";
	char t2[] = "world! I love";
	char t3[] = "world I low";

	printf("%d %d %d %d\n", strend(s, t0), strend(s, t1), strend(s, t2), strend(s, t3));
	return;
}
