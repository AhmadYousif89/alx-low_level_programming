#include <stdlib.h>
#include <stdio.h>

/**
 * main - Entry point
 * Print all possible combinations of two two-digit numbers using putchar();
 * Return: Always 0 (Success)
 */

int main(void)
{
	int first_digits, second_digits;

	for (first_digits = 0; first_digits <= 99; first_digits++)
	{
		for (second_digits = first_digits; second_digits <= 99; second_digits++)
		{
			/* Prevent dublicate numbers */
			if (second_digits != first_digits)
			{
				/* Print the first digit of the first two-digits ==> 0 .. 9 */
				putchar(first_digits / 10 + 48);
				/* Print the second digit of the first two-digits ==> 01 will print 1 */
				putchar(first_digits % 10 + 48);
				putchar(' ');

				/* Print the second two-digit number */
				putchar(second_digits / 10 + 48);
				putchar(second_digits % 10 + 48);

				/* Add a comma and space if not the last combination */
				if (first_digits != 98 || second_digits != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
