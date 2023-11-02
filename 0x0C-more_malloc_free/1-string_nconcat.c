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
	unsigned int len_s1 = (s1 != NULL) ? strlen(s1) : 0;
	unsigned int len_s2 = (s2 != NULL) ? strlen(s2) : 0;
	unsigned int concat_len = len_s1 + ((n >= len_s2) ? len_s2 : n);

	char *concatenated = malloc(concat_len + 1);
	if (concatenated == NULL)
		return NULL;

	if (s1 != NULL)
		strcpy(concatenated, s1);
	else
		concatenated[0] = '\0';

	strncat(concatenated, s2, n);
	concatenated[concat_len] = '\0';

	return concatenated;
}
