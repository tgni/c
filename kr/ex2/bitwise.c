#include <stdio.h>
#include "types.h"

/*
 * when doing BITMASK(31, 32) compiler gives a warning that 
 * complaining n is greater than width of type, but give the
 * result of 0xFFFFFFFF.
 * while In the running time, when using variable n = 32
 * bitmask will equals to zero.
 */
#define BITMASK(p, n)	((~(~0 << (n))) << ((p) + 1 - (n)))
//#define BITMASK32(p)	((~(~0 << (32))) << ((p) + 1 - (32)))
#if 0
static unsigned BITMASK(int p, int n)
{
	return (~(~0 << n)) << (p + 1 - n);
}
#endif

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~BITMASK(p, n)) | (y & BITMASK(p, n));
}

unsigned invert(unsigned x, int p, int n)
{
	return (x & ~BITMASK(p, n)) | ~(x & BITMASK(p, n));
}

unsigned rightrot(unsigned x, int n)
{
	//return (x >> n) | ((x & ~(~0 << n)) << (32 - n));
	return (x >> n) | (x << (32 - n));
}

unsigned leftrot(unsigned x, int n)
{
	return (x << n) | (x >> (32 - n));
}

/* generic code */
//#define rightrot(type, x, n)	(((x) >> (n)) | (((x) & BITMASK((n) - 1, (n))) << (sizeof(type) * 8 - (n))));

void printbits(unsigned x)
{
	int i;

	for (i = 31; i >= 0; --i) {
		printf("%1d", getbits(x, i, 1));
		if (i % 8 == 0)
			printf(" ");
	}
	printf("\n");
	
	return;
}

/*
	for (p = 0; p < 32; ++p) {
		for (n = 1; n <= p + 1; ++n) {
			printf("p: %d n:%d, bitmask:%x\n", p, n, BITMASK(p, n));
			printbits(BITMASK(p, n));
		}
	}
	printbits(BITMASK(31, 32)); //producing warning
*/

main()
{
#if 1
	int p, n;
	int a = 0xfff0;
	int b = 0x000f;
	printf("a:\n");
	printbits(a);
	printf("set a from bit 3 to 0 of 0x000f\n");
	printbits(setbits(a, 3, 4, b));
	printf("invert bits from bit 4 to 0\n");
	printbits(invert(a, 4, 5));
	printf("right rotate a of 10 bits\n");
	printbits(rightrot(a, 10));
#else
	/* test right shift with signed int */
	int c = 0xf0000001;
	printf("%d, %x, %ld, %u\n", c, c, c, c);
	printbits(c);
	printbits(c >> 1);
	printbits(c >> 2);
#endif

	return;
}
