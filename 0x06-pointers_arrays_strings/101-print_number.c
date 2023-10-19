#include <stdio.h>
#include "main.h"

/**
 * print_number - Print out integers using _putchar
 * @n: number type int
 * Return: void
 */

void print_number(int n)
{
	unsigned int num;

	/* Case: n is negative -- print (-) and negate (n) */
	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
		num = n;
	/* Recursively invoking (print_number) to print the numbers in reverse */
	if (num / 10)
		print_number(num / 10);
	/* Print the last number of (num) each time (print_number) is invoked */
	_putchar((num % 10) + '0');
}
