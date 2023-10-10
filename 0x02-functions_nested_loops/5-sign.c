#include "main.h"

/**
 * print_sign - Check for the value of (n) and print a sign accordingly.
 * Description:
 * print (+) if (n) is greater than zero
 * print (0) if (n) is zero
 * print (-) if (n) is less than zero
 * @n: arg of type int
 * Return: 1 (n > 0) or 0 (n == 0) or -1 (n < 0)
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
