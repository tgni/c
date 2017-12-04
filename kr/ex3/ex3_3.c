/*
 * File: expand.c
 * Description:
 * History:
 *	Jan 10, 2016	Daniel Ni	Create
 */

#include <stdio.h>
#include <ctype.h>

void expand(char dst[], const char src[])
{
	int i, j, k, l;
	char c;

	for (i = 0, l = 0; src[i] != '\0'; i++) {
		dst[l++] = src[i];
		if (islower(src[i]) || isdigit(src[i])) {
			j = i + 1;
			if (src[j] == '\0')
				continue;

			if (src[j] == '-') {
				k = j + 1;
				if (src[k] == '\0')
					continue;

				if ((islower(src[i]) && islower(src[k]) && src[i] < src[k])
					|| (isdigit(src[i]) && isdigit(src[k]) && src[i] < src[k])) {
					for (c = src[i] + 1; c < src[k]; c++) {
						dst[l++] = c;
					}
					i++;
				}
			}
		}
	}
	dst[l] = '\0';

	return;
}

main()
{
	char a[] = "-a-1-8-b-o-9a-0-";	
	char b[256];

	expand(b, a);
	printf("a: %s\n", a);
	printf("b: %s\n", b);

	return;
}
