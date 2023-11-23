#include "main.h"

/**
 * print_binary - Print numbers in binary
 * @n: the number to print
 * Return: Nothing
 */
void print_binary(unsigned long int n)
{
	/* The most significant bit (MSB) position, e.g., (63) for a 64-bit */
	int bit = sizeof(n) * 8 - 1;
	int printed = 0;

	while (bit >= 0)
	{
		/* Get the value of the current bit by right shifting (n) */
		/* by 'bit' positions and bitwise AND with 1 */
		if ((n >> bit) & 1)
		{
			putchar('1');
			printed = 1;
		}
		/* If 'bit' is equal to 0 or it was printed, then print '0' */
		else if (printed || bit == 0)
			putchar('0');
		/* Decrement 'bit' to move toward the MSB */
		bit--;
	}
}
