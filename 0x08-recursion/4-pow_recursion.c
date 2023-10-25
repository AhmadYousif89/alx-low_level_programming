#include <stdio.h>
#include "main.h"

/**
 * _pow_recursion - Get power of a number | recursion
 * @x: number
 * @y: power of x
 * Return: void
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
