#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concat 2 strings and allocate memory using malloc
 * @s1: pointer type char
 * @s2: pointer type char
 * @n: number
 * Return: on fails NULL or Pointer to the allocated memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	int s1len = strlen(s1);
	char *ps;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	ps = malloc(s1len + n + 1); /* Allocate mem for the new str */

	if (ps == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		ps[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0' && j < n)
	{
		ps[i++] = s2[j];
		j++;
	}

	return (ps);
}
