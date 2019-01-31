/* File: __atof.c */
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//#define _GNU_SOURCE

/* __atof: convert string s to double */
#if 0
double __atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}
#endif

double __atof(char s[])
{
	double val, power, power2;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	power2 = 1.0;
	if (s[i] == 'E' || s[i] == 'e') {
		i++;
		if (s[i] != '-')
			goto out;
		i++;
		for (power2 = 0.0; isdigit(s[i]); i++) {
			power2 = 10.0 * power2 + (s[i] - '0');
		}
		power2 = pow(10.0, power2);
	}
out:
	return sign * val / power / power2;
}

main()
{
	double sum, __atof(char []);
	char *line = NULL;
	size_t len;
	//int getline(char line[], int max);

	sum = 0;
	while (getline(&line, &len, stdin) > 0)
		printf("\t%g\n", sum += __atof(line));	
	if (line)
		free(line);

	return 0;
}
