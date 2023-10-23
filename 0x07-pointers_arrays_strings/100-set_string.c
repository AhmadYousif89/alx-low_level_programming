#include <stdio.h>

/**
 * set_string - Set the value of a pointer to a char
 * @s: pointer to pointer type char
 * @to: pointer type char
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
