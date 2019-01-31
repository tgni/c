/* File: longest_line.c */
/* print the longest line */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	char *longest = NULL;
	int len = 0;
	int max = 0;
	int read;
	
	while ((read = getline(&line, &len, stdin)) > 0)
		if (read > max)	{
			max = read;	
			free(longest);
			longest = malloc(len);
			if (!longest) {
				printf("no memory!\n");
				return -1;
			}
			strcpy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);

	free(line);
	free(longest);

	return 0;
}
