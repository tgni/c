#include <stdio.h>

struct unpacked {
	char c1;
	int  i1;
	char c2;
	int  i2;
};

struct packed_one {
	char c1;
	int  i1 __attribute__ ((packed));
	char c2;
	int  i2;
};

struct packed_all {
	char c1;
	int  i1;
	char c2;
	int  i2;
} __attribute ((packed));

int main()
{
	printf("sizeof(struct unpacked) %d sizeof(struct packed_one) %d "
	       "sizeof(struct packed_all) %d\n", sizeof(struct unpacked), 
	       sizeof(struct packed_one), sizeof(struct packed_all));

	return 0;
}
