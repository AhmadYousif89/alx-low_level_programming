#include "main.h"

/**
 * print_last_digit - Return and print the last digit of (n).
 * Description:
 * Check and return the last value of (n) after negating the value if negative.
 * @n: arg of type int
 * Return: (n)
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (n < 0)
		last_digit = -last_digit;

	_putchar(last_digit + '0');
	return (last_digit);
}
