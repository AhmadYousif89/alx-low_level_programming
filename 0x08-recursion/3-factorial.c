#include <stdio.h>
#include "main.h"

/**
 * factorial - Get factorial of number | recursion
 * @n: number to factor
 * Return: void
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
