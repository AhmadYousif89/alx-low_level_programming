#include <stdlib.h>

/**
 * str_concat - Concatenate two strings by dynamically allocating memory
 * @s1: pointer type char
 * @s2: pointer type char
 * Return:
 * NULL if s1 or s2 = NULL
 * Pointer to a newly allocated space which contain s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	int s1Len = 0, s2Len = 0, i = 0;
	char *ps;

	while (s1[s1Len] != '\0')
		s1Len++;
	while (s2[s2Len] != '\0')
		s2Len++;

	ps = (char *)malloc((sizeof(char) * s1Len + s2Len) + 1);

	if (ps == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		ps[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
		ps[s1Len++] = s2[i++];

	return (ps);
}
