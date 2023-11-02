#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concat two strings and allocate memory using malloc
 * @s1: pointer type char
 * @s2: pointer type char
 * @n: number
 * Return: on fails NULL or Pointer to the allocated memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	int s1len = strlen(s1);
	int s2len = strlen(s2);
	int str_len = s1len + s2len + 1;
	char *ps;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	ps = malloc(str_len); /* Allocate mem for the new str */

	if (ps == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		ps[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
		ps[s1len++] = s2[i++];

	return (ps);
}
