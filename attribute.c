/* File: attribute.c */
#include <stdio.h>

struct a_struct {
        char a;
        int b;
        long c;
} __attribute__ ((aligned(4)));

struct b_struct {
        char a;
        int b __attribute__ ((packed));
        long c __attribute__ ((packed));
};

struct c_struct {
        char a;
        int b;
        long c;
} __attribute__ ((packed));

struct d_struct {
	char a;
	int b;
	struct {
		short a:12;
		short b:4;	
	} c;
} __attribute__((packed));

int main(void)
{
        printf("a: %d\n", sizeof(struct a_struct));
        printf("b: %d\n", sizeof(struct b_struct));
        printf("c: %d\n", sizeof(struct c_struct));
        printf("d: %d\n", sizeof(struct d_struct));

	return 0;
}
