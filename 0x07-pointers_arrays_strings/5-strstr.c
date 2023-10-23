#include <stdio.h>

/**
 * _strstr - Find the first occurrence of the substring (needle) in (haystack)
 * @haystack: pointer type char
 * @needle: pointer type char
 * Return: Pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		/* Return the pointer to the beginning of the located substring */
		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}
