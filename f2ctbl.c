/* File: f2ctbl.c */
#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step  = 10;
	
	printf("Fahrenheit    Celsius\n");
	printf("=========================\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f           %6.1f\n", fahr, celsius);
		fahr += step;
	}

	lower = -100;
	upper = 100;
	step  = 10;

	printf("Celsius    Fahrenheit    \n");
	printf("=========================\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%6.1f         %3.0f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}
