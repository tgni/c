/* File: line_longer_than_80.c */
/* print the longest line */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NR_READ_LIMIT	(80)

typedef struct string_s {
	int len;
	char *str;
	struct string_s *next;
} string;

int main(void)
{
	char *line = NULL;
	string *str = NULL;
	int len = 0;
	int max = 0;
	int read;
	
	while ((read = getline(&line, &len, stdin)) > 0)
		if (read > NR_READ_LIMIT) {
			//TODO
		}

	//display strings
	//free strings
	
	return 0;
}
