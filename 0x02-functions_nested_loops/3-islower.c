#include "main.h"

/**
 * _islower - Check for lowercase characters
 * Description - Check and return (1) if lowercase character, (0) otherwise
 * @c: arg of type int
 * Return: 1 (c is lowercase) or 0 (otherwise)
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
