#include "main.h"

/**
 * set_bit - Set the value of a bit to 1 at a given index
 * @n: pointer to the number
 * @index: the index of the bit
 * Return: 1 on success or -1 on failuer
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bit = sizeof(*n) * 8 - 1;
	/* Index out of range = failuer */
	if (index > bit)
		return (-1);
	/* Check if the result of right shifting the value of (n)*/
	/* by the index and bitwising with (& 1) will equal (0) */
	if (((*n >> index) & 1) == 0)
	{
		/* Set the bit value to (1) */
		*n = *n | (1 << index);
		return (1);
	}

	return (-1);
}
