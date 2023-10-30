#include <stdlib.h>
#include <string.h>
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
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	result = malloc(strlen(s1) + strlen(s2) + 1);

	if (result == NULL)
		return (NULL);

	strcpy(result, s1);
	strcat(result, s2);

	return (result);
}
