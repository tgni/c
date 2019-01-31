#include <stdio.h>

#ifndef time_after
#define time_after(a,b)		((long)(b) - (long)(a) < 0)
#endif

#ifndef time_before
#define time_before(a,b)	time_after(b,a)
#endif

#ifndef time_after_eq
#define time_after_eq(a,b)	((long)(a) - (long)(b) >= 0)
#endif

#ifndef time_before_eq
#define time_before_eq(a,b)	time_after_eq(b,a)
#endif

#ifndef time_diff
#define time_diff(a,b)		(unsigned long)((long)(a) - (long)(b))
#endif


main(void)
{
	unsigned long a, b, adv;

	a = 500;
	b = 1000;
	adv = 1500;

	printf("long a: %d long b: %d long b-adv: %d\n", (long)a, (long)b, (long)(b-adv));

	printf("time before a & b-adv: %d\n", time_before(a, b-adv));

	a = 600;

	printf("time before a & b-adv: %d\n", time_before(a, b-adv));

	a = 700;

	printf("time_before a & b-adv: %d\n", time_before(a, b-adv));

	return;
}
