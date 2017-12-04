/* File: testwhile.c */
#include <stdio.h>

#define IDX_MAX		(8)

int get_idx_status(int idx)
{
	static cnt = 0;
	if (++cnt > IDX_MAX) {
		cnt = 0;	
		return 1;
	}
	return 0;
}

int main(void)
{
	int idx = 0;

//	while (idx < IDX_MAX && (get_idx_status(idx) ? 1 : ++idx));
	while (idx < IDX_MAX) {
		if(get_idx_status(idx)) {
			++idx;	
		}
	}

	printf("%d\n", idx);

	return 0;
}
