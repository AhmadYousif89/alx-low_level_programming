#include "main.h"

/**
 * _isupper - Check for uppercase characters
 * Description - Check and return (1) if uppercase character, (0) otherwise
 * @c: arg of type int
 * Return: 1 (c is uppercase) or 0 (otherwise)
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
