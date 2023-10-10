#include "main.h"

/**
 * jack_bauer - Print 24 hour (00:00 .. 23:59) format.
 * Description:
 * Print out the characters (00:00) to (23:59).
 * Return: Void
 */
void jack_bauer(void)
{
	int first_digits, second_digits;

	for (first_digits = 0; first_digits < 24; first_digits++)
	{
		for (second_digits = 0; second_digits <= 59; second_digits++)
		{
			/* Print the first two digits of the hour format ==> (00 .. 23) */
			_putchar(first_digits / 10 + '0');
			_putchar(first_digits % 10 + '0');

			_putchar(':');
			/* Print the second two digits of the hour format ==> (00 .. 59) */
			_putchar(second_digits / 10 + '0');
			_putchar(second_digits % 10 + '0');
			_putchar('\n');
			/* The result is a series of 00:00 till 23:59 ==> wc = 1440 */
		}
	}
}
