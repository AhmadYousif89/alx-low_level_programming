#include "main.h"

/**
 * print_number - Print integer numbers
 * Description - Print any given number using only _putchar
 * @n: number
 * Return: Void
 */

void print_number(int n)
{
	int reversed_n = 0;

	/* Case: n = 0 */
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	/* Case: n is negative = -98 */
	if (n < 0)
	{
		/* Print (-) and negate the number (n) */
		_putchar('-');
		n = -n;
	}
	/* n = 98 */
	/* Loop over (n) and reverse it => 98 to 89 in 2 iterations */
	while (n > 0)
	{
		/* On first iteration (reversed_n) => 8 */
		/* On second iteration (reversed_n) => 9 */
		reversed_n = reversed_n * 10 + n % 10;
		n /= 10;
	}
	/* Print the reversed characters => 98 */
	while (reversed_n > 0)
	{
		_putchar('0' + reversed_n % 10);
		reversed_n /= 10;
	}
}
