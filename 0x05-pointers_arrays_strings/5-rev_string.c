#include "main.h"

/**
 * rev_string - Reverse a string
 * @s: data of type char *
 * Return: void
 */

void rev_string(char *s)
{
	int i = 0, j, len;
	int x;

	while (s[i] != '\0')
	{
		i++;
	}

	len = i - 1;

	for (j = 0; j < len; j++)
	{
		x = *(s + len);		   /* value of last char */
		*(s + len) = *(s + j); /* last char = first char */
		*(s + j) = x;		   /* first char = last */
		len--;				   /* decrement len on each iteration*/
	}
}
