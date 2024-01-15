#include "main.h"

/**
 * _isalpha - Check if character is lowercase or uppercase alphabet
 * Description - Check and return (1) if lower or upper alphabet, (0) otherwise
 * @c: arg of type int
 * Return: 1 (c is alphabet) or 0 (otherwise)
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
