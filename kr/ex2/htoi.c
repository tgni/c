/**
 * htoi - convert hex string to its value
 *  which is equvilent to strtoul
 */
#include <stdio.h>

static inline int convert(char c)
{
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else if (c >= 'a' && c <= 'f') {
		return c - 87;
	} else if (c >= 'A' && c <= 'F') {
		return c - 55;
	} else {
		return -1;
	}

}

int htoi(char s[])
{
	char *p = s;
	int i = 0;
	int c = -1;

	if (s && s + 1 && s + 2
		&& s[0] == '0' 
		&& (s[1] == 'X' || s[1] == 'x')
		&& s[2] != '\0') {

		p += 2;
	}

	for ( ; *p != '\0'; p++) {
		if ((c = convert(*p)) != -1) {
			i = i * 16 + c;	
		} else {
			return -1;
		}
	}
	return i;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: ./test 0x1234546\n");
		return -1;
	}

	printf("convert result: 0x%x\n", htoi(argv[1]));

	return 0;
}
