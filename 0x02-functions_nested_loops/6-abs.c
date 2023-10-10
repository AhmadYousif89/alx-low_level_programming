#include "main.h"

/**
 * _abs - Return the absolute value of (n).
 * Description: Check and return the value of (n) as a positive integer if not.
 * @n: arg of type int
 * Return: (n)
 */
int _abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}
