/*
 * bitcount.c - bit counting is an interesting problem.
 * we can found at least four solution
 * 1. normal way, shift O(n)
 * 2. use trick, when zero is more than one, this way is
 * more efficient.
 * 3. hamming weight O(log(n))
 * 4. looking up table O(1), if we have enough space
 * 5. also we can using looking up one 8-bits table, and
 * divide string into small pieces.
 */

#include <stdio.h>
/* bitcount: count 1 bits in x */
int bitcount0(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;

	return b;
}

int bitcount1(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= x - 1)
		++b;

	return b;
}

/**
 * hweightN - returns the hamming weight of a N-bit word
 * @x: the word to weigh
 *
 * The Hamming Weight of a number is the total number of bits set in it.
 */

unsigned hweight32(unsigned w)
{
	unsigned res = w - ((w >> 1) & 0x55555555);
	res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
	res = (res + (res >> 4)) & 0x0F0F0F0F;
	res = res + (res >> 8);
	return (res + (res >> 16)) & 0x000000FF;
}

main()
{
	unsigned x = 0x10101010;

	printf("%d %d %d \n", bitcount0(x), bitcount1(x), hweight32(x));

	return;
}
