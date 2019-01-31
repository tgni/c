/* File: print_words_length.c */
#include <stdio.h>
/* OOP implementation */
typedef struct statis {
	char name;
	int cnt;
} statis_t;

#define NR_ASCII	(128)
statis_t STATIS[NR_ASCII];

void init_statis(void)
{
	int i;
	statis_t *p;

	for (i = 0; i < NR_ASCII; ++i) {
		p = &STATIS[i];	
		p->name = i;
		p->cnt  = 0;
	}
}

void print_statis(void)
{
	statis_t *p;
	int i;
	
	for (i = 0; i < NR_ASCII; ++i) {
		p = &STATIS[i];
		printf("%c : %d\n", p->name, p->cnt);
	}
}

main()
{
	int c;

	init_statis();
	while ((c = getchar()) != EOF) {
		++STATIS[c].cnt;
	}
	print_statis();
}
