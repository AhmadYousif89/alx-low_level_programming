#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */

void print_remaining_days(int month, int day, int year)
{
	/* Correctly checking for leap year */
	if (year % 4 == 0 || (year % 400 == 0 && year % 100 != 0))
	{
		/* If it is a leap year but the month is not February add 1 day */
		if (month > 2 && day >= 60)
		{
			day++;
		}

		printf("Day of the year: %d\n", day);
		printf("Remaining days: %d\n", 366 - day);
	}
	/* The given date is NOT in a leap year */
	else
	{
		/* But the date has 29 day instead of 28 for the month of Feb => ✖ */
		if (month == 2 && day == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		}
		/* Date is NOT in month of February and day is between 1 and 31 => ✔ */
		else
		{
			printf("Day of the years: %d\n", day);
			printf("Remaining days: %d\n", 365 - day);
		}
	}
}
