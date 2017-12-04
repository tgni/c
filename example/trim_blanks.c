/* File: trim_blanks.c */
/* File: trim_blanks.c
 * Description:
 *	replace each string of one or more blanks by a single blank
 */ 

#include <stdio.h>
main()
{
	int c, old = EOF;

	while ((c = getchar()) != EOF) {
		if (c == ' ' && old == ' ')
			continue;
		putchar(c);
		old = c;
	}
}
