#include <stdio.h>
#include "main.h"

/**
 * is_prime_number - Check for prime number | recursion
 * @n: number to sqrt
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	int x;

	if (n > 1 && n % 2 != 0)
		x = 1;
	else
		x = 0;
	return (x);
}
