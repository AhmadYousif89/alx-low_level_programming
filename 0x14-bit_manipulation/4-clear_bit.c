#include "main.h"

/**
 * clear_bit - Set the value of a bit to 0 at a given index
 * @n: pointer to the number
 * @index: the index of the bit
 * Return: 1 on success or -1 on failuer
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bit = sizeof(*n) * 8 - 1;
	/* Index out of range = failuer */
	if (index > bit)
		return (-1);

	if (((*n >> index) & 1) == 1)
	{
		/* Set the bit value to (0) */
		*n ^= (1 << index);
		return (1);
	}

	return (-1);
}
