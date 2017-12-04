/*
 * File: __getline.c - pointer version not use array
 * Description:
 * History:
 *	Jan 23, 2016	Daniel Ni	Create
 */ 
#include <stdio.h>

#define MAXLINE		1000	/* maximum input file length */

int __getline(char *s, int max);
int strindex(char *s, char *t);

char pattern[] = "ould";

/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int found = 0;

	while (__getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

int __getline(char *s, int lim)
{
	int c, len;

	len = lim;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return  (len - lim);
}

int strindex(char *s, char *t)
{
	char *r = s, *p, *q;

	for ( ; *r != '\0'; r++) {
		p = r; q = t;
		for ( ; *q != '\0' && *p == *q; p++, q++)
			;
		if (q != t && *q == '\0')	//q has context, and match the end
			return (r - s);		// return position
	}
	return -1;
}
