#include <stdio.h>
#include "main.h"

/**
 * get_sqrt - Calc the square root of a number
 * @n: integer number
 * @v: integer number
 * Return: the sqrt value
 */
int get_sqrt(int n, int v)
{
	if (v * v == n)
		return (v);
	if (v * v < n)
		return (get_sqrt(n, (v + 1)));
	return (-1);
}

/**
 * _sqrt_recursion - Get square root of a number | recursion
 * @n: number to sqrt
 * Return: void
 */
int _sqrt_recursion(int n)
{
	return (get_sqrt(n, 1));
}
