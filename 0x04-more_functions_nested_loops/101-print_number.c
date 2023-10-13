#include "main.h"

/**
 * print_number - Print integer numbers
 * Description - Print any given number using only _putchar
 * @n: number
 * Return: Void
 */

void print_number(int n)
{
	unsigned int num = n;
	unsigned int reversed_n = 0;

	/* Case: n = 0 */
	if (num == 0)
	{
		_putchar('0');
		return;
	}
	/* Case: n is negative => -98 */
	if (n < 0)
	{
		/* Print (-) and negate the number (num) */
		_putchar('-');
		num = -n;
	}
	/* n = 98 */
	/* Loop over (num) and reverse it => 98 to 89 in 2 iterations */
	while (num > 0)
	{
		/* On first iteration (reversed_n) => 8 */
		/* On second iteration (reversed_n) => 9 */
		reversed_n = reversed_n * 10 + num % 10;
		num /= 10;
	}
	/* Print the reversed characters => 98 */
	while (reversed_n > 0)
	{
		_putchar('0' + reversed_n % 10);
		reversed_n /= 10;
	}
}
