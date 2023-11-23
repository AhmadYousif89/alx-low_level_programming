#include "main.h"

/**
 * flip_bits - Flip the bits of a given number to get to another number
 * @n: the number to flip
 * @m: the modified number
 * Return: 1 on success or -1 on failuer
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int xor_result = n ^ m;

	while (xor_result)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}