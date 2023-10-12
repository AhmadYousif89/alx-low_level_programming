#include <stdio.h>

/**
 * main - Entry point
 * Description: Calculate the largest prime factor for a given number.
 * Return: (0)
 */

int main(void)
{
	unsigned long num = 612852475143;
	unsigned long largest_prime_factor = 2;

	printf("num: %lu\n", num);
	/* Loop over (num) until it reach (1) */
	while (num > 1)
	{
		if (num % largest_prime_factor == 0)
		{
			num /= largest_prime_factor;
		}
		else
			/* Increment the largest possible prime factor */
			largest_prime_factor++;
	}

	printf("largest_prime_factor: %lu\n", largest_prime_factor);

	return (0);
}
