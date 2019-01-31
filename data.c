/* File: data.c */
#include <stdio.h>

typedef unsigned char uint8_t;

typedef struct data_s {
	uint8_t a;
	uint8_t b[0];
} __attribute__((__packed__)) data_t;

void main(void)
{
	printf("sizeof(data_t): %d\n", sizeof(data_t));

	return 0;
}
