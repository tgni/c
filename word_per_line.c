/* File: word_per_line.c */
/*
 * one word, one line
 */

#include <stdio.h>

main()
{
	int c, old = EOF;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {	
			if (old == ' ' || old == '\t')
				continue;
			else
				putchar('\n');
		} else {
			putchar(c);	
		}
		old = c;
	}
}

/* 
 * What if the last word with continuing on blank or tab?
 * The last blank or tab cannot be detected as followed by EOF.
 * Here solution should be use memory to save all words, and
 * trim last blank or tab. As for which way to save words doesn't
 * matter.
 * And we don't escape special chars or punctuation such as: 
 * (,.:;...) comma, full stop, colon, semicolon ... etc.
 */
