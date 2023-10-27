#include <stdio.h>

/**
 * _strspn - Get the length of a prefix substring
 * @s: pointer type char
 * @accept: pointer type char
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;
	int found;

	for (i = 0; s[i] != '\0'; ++i)
	{
		found = 0;
		for (j = 0; accept[j] != '\0'; ++j)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
			break;
	}

	return (i);
}
