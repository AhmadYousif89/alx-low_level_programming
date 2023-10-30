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

	while (str[len] > '\0')
		len++;

	if (len == 0)
		return (NULL);

	pstr = (char *)malloc(sizeof(char) * len);

	if (pstr == NULL)
		return (NULL);

	while (str[c] > '\0')
	{
		pstr[c] = str[c];
		c++;
	}

	return (pstr);
}
