/* File: mem_zero.c */
#include <stdio.h>
#include <string.h>

unsigned char SRC[8] = {1, 2, 3, 4, 5, 6, 7, 8};
unsigned char DST[8];

main()
{
	//memcpy((void *)DST, NULL, 8);
	//memcpy(NULL, (void *)SRC, 8);
	memcpy(NULL, NULL, 0);

	return 0;
}
