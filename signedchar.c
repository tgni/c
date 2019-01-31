/* File: signedchar.c */
#include <stdio.h>


main(void)
{
	signed char array[32] = "hello world\n";
	signed char *a = array;
	char *b = NULL;
	b = a;
	printf("%s\n", b);

	return 0;
}
