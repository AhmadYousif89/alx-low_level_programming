#include <stdio.h>
#include "main.h"

/**
 * _strlen_recursion - Get length of a string | recursion
 * @s: pointer type char
 * Return: void
 */
int _strlen_recursion(char *s)
{
	int len = 0;

	if (*s == '\0')
		return (len);
	len++;

	return (len + _strlen_recursion(s + 1));
}
