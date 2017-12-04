#include <stdio.h>

int free_ptr(char *p)
{
	p = NULL;
}

int main(void)
{
	char *p = NULL;
	char str[] = "hello world\n";

	p = str;
	printf("Before: %s\n", p);

	free_ptr(p);
	printf("After free p: %s\n", p);
}
