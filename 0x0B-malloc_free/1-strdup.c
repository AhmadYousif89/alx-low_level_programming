#include <stdlib.h>

/**
 * _strdup - Dynamically allocating a space for string in memory
 * @str: pointer type char
 * Return: NULL if str = NULL | Pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	int len = 0, c = 0;
	char *pstr;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	pstr = (char *)malloc((sizeof(char) * len) + 1);

	if (pstr == NULL)
		return (NULL);

	while (str[c] != '\0')
	{
		pstr[c] = str[c];
		c++;
	}

	return (pstr);
}
