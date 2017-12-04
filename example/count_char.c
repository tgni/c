/* File: count_char.c */
#include <stdio.h>
/* how about OOP? but lose simplicity */
#if 0
main()
{
	int c, nspace = 0, ntab = 0, nnewline = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++nspace;	
		} else if (c == '\t') {
			++ntab;
		} else if (c == '\n') {
			++nnewline;	
		}
	}
	printf("num space: %d, num tab: %d, num newline: %d\n",
		nspace, ntab, nnewline);
}
#endif

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
