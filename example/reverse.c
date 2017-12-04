/* File: reverse.c */
#include <stdio.h>
static inline void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

main()
{
	char *line = NULL;
	int  len = 0;
	int read;
	int i;

	while ((read = getline(&line, &len, stdin)) != -1) {

		for (i = 0; i < read / 2; ++i)
			swap(&line[i], &line[(read - 1) - i]);
		printf("%s\n", line);
	}

	free(line);
}
