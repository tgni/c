#include <stdio.h>
#include "types.h"

typedef struct {
	uint32_t a :17;
	uint32_t b :17;
	uint32_t c :15;
	uint32_t d :15;
} test_t;

test_t T;

int main()
{
	int32_t i;

	printf("sizeof(T): %d\n", sizeof(T));
	for (i = 0; i < 32; ++i) {
		T.a++;
		T.b++;
		T.c++;
		T.d++;
		printf("a: %d b: %d c: %d d: %d\n", T.a, T.b, T.c, T.d);
	}
	return 0;
}
