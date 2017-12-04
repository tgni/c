/*
 * Copyright: (c) 2006-2007, 2008 Triductor Technology, Inc.
 * All Rights Reserved.
 *
 * File:	daytab.c
 * Purpose:	the routines day_of_year and month_day in 
 *		pointer version.
 * History:
 *	Feb 24, 2016	Tgni	Create
 */ 
#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;

	if (year < 0 || (month < 0 || month > 12))
		return -1;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	if (day < 0 || day > daytab[leap][month])
		return -1;

	p = &daytab[leap][1];
	while (--month)
		day += *p++;

	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;

	*pmonth = -1;
	*pday = -1;

	if (year < 0 || yearday < 0)
		return;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	if (yearday - leap > 365)
		return;

	p = &daytab[leap][1];
	*pmonth = 1;
	while (yearday > *p) {
		yearday -= *p++;
		(*pmonth)++;
	}
	*pday = yearday;

	return;
}

int main(int argc, char *argv[])
{
	int year, month, day, yearday;

	if (argc != 4) {
		printf("Usage: ./daytab [year] [month] [day]\n");	
		return -1;
	}

	year  = strtoul(argv[1], NULL, 0);
	month = strtoul(argv[2], NULL, 0);
	day   = strtoul(argv[3], NULL, 0);

	yearday = day_of_year(year, month, day);
	printf("yearday of today: %d\n", yearday);

	month = 0;
	day = 0;
	month_day(year, yearday, &month, &day);

	printf("today is: %d/%d/%d\n", day, month, year);

	return 0;
}
