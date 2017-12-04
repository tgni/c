/* File: alloca_test.c */
#include <stdio.h>
#include <string.h>
#include <alloca.h>
int main(void)
{
	char *p = alloca(10);

	strcpy(p, "hello world");

	printf("%s\n", p);
	
	return 0;
}
