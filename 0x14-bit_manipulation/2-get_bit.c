#include "main.h"

/**
 * get_bit - Get the value of a bit at a given index
 * @n: number
 * @index: the index of the bit
 * Return: The value of the bit at the given index or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* Index out of range */
	if (index >= sizeof(n) * 8)
		return (-1);
	/* Right shift the number by the given index then bitwise */
	/* the result with (&) 1 to get the bit (0 or 1)*/
	return ((n >> index) & 1);
}
