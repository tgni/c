/* File: same_var_and_func.c */
#include <stdio.h>

//int a[];
//int a;

void a()
{
	printf("hello world\n");
}

main()
{
	int a[12];

	a[0] = 1;

	//a();

	return 0;
}

/**
 * Conclusion:
 *	if the same symbol used both function and variable, it is
 *	not allowed. But if you do not invoke the function, just
 *	define the function, and use the same symbol to define a
 *	local variable, do some actions on it, the compiler never
 *	complain. Global variable and function with the same
 *	symbol will not allowed.
 *
 **/

