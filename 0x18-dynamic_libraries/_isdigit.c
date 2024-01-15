#include "main.h"

/**
 * _isdigit - Check if character is digit
 * Description - Check and return (1) if character is digit, (0) otherwise
 * @c: arg of type int
 * Return: 1 (c is digit) or 0
 */

int _isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
