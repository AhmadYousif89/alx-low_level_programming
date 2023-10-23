#include <stdio.h>

/**
 * _strstr - Find the first occurrence of the substring (needle) in (haystack)
 * @haystack: pointer type char
 * @needle: pointer type char
 * Return: Pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	while (*haystack != '\0')
	{
		for (i = 0; needle[i] != '\0'; i++)
		{
			if (*haystack == needle[i])
				return (needle);
		}
		haystack++;
	}
	return (NULL);
}
