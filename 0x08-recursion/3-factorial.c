#include <stdio.h>
#include "main.h"

/**
 * factorial - Get factorial of number | recursion
 * @s: pointer type char
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
