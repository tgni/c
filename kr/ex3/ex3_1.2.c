/* 
 * Andrew Tesker
 * krx30102.c
 *
 * History:
 *	xxx			Andrew Tesker	Create
 *	Jan 10, 2016		Daniel Ni	Modify
 *
 * Note:
 * 1. the original code is a bad style. I correct it.
 * 2. binsearch routine should be dumped to help me understand the logic.
 * 3. test 2 cases, one is odd array numbers, another is even array numbers.
 * 4. compare two version of binsearch using system clock function to 
 * calculate time spent.
 *
 */

#include <stdio.h>

#define NELEM(array)	(sizeof(array) / sizeof(array[0]))
/*  Performs a binary search for element x
    in array v[], which has n elements      */

int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while ( low <= high ) {
		mid = (low + high) / 2;
		printf("low:%d high:%d mid:%d v[mid]:%d\n", low, high, mid, v[mid]);
		if ( x < v[mid] )
			high = mid - 1;
		else if ( x > v[mid] )
			low = mid + 1;
		else
			return mid;
	}
	printf("low:%d high:%d mid:%d v[mid]:%d\n", low, high, mid, v[mid]);

	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low < high) {
		mid = (low + high)/2;
		//printf("low:%d high:%d mid:%d v[mid]:%d\n", low, high, mid, v[mid]);
		if (x <= v[mid]) 
			high = mid;
		else 
			low = mid + 1;
	}
	//printf("low:%d high:%d mid:%d v[mid]:%d\n", low, high, mid, v[mid]);

	/* return condition is low equals to high */
	return (x == v[low]) ? low : -1;
	//return (x == v[high]) ? high : -1;
}

void print_array(int a[], int n)
{
	int i;

	for (i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void)
{
	int test[]={1, 3, 5, 7, 9, 11, 13, 15};
	int i, r;
	
	print_array(test, NELEM(test));
#if 0
	idx = binsearch(-1, test, NELEM(test));
	if (idx != -1)
		printf("found\n");
	else
		printf("not found\n");
#endif

	for (i = 0; i < NELEM(test); ++i) {
		r = binsearch2(test[i], test, NELEM(test));
		if (r != -1)
			printf("found %d at %d\n", test[i], r);
		else
			printf("not found %d\n", test[i]);
	}


	return 0;

}
