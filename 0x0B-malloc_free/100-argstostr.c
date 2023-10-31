#include <stdlib.h>
#include <string.h>

/**
 * argstostr - Concatonate all arguments in one string | malloc
 * @ac: arg count
 * @av: pointer to arg vector
 * Return: NULL if ac == 0 or av == NULL or on fails
 * otherwise, a pointer to a new string
 */
char *argstostr(int ac, char **av)
{
	int i, j, total_args_len, cur_pos = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	/* Get total length of all args including spaces and newline */
	for (i = 0; i < ac; i++, total_args_len++)
		total_args_len += strlen(av[i]) + 1; /* (+1) for '\n' */
	/* Allocate memory for the new string */
	str = (char *)malloc((sizeof(char) * total_args_len) + 1);
	/* Allocation failed */
	if (str == NULL)
		return (NULL);
	/* Concatonate all args */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, cur_pos++)
			str[cur_pos] = av[i][j];

		str[cur_pos] = '\n';
		cur_pos++;
	}
	str[cur_pos] = '\0'; /* Add the null terminator after last char */

	return (str);
}
