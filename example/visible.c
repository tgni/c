/* File: visible.c */
/*
 * visible blanks, tabs, backslash
 */

#include <stdio.h>
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			printf("\\b");
		} else if (c == '\t') {
			printf("\\t");
		} else if (c == '\\') {
			printf("\\\\");	
		} else {
			putchar(c);	
		}
	}
}
