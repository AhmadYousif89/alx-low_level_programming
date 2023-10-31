#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Track the word count in a given string
 * @str: pointer type char
 * Return: the word count
 */
int count_words(char *str)
{
	int count = 0, is_word = 0;

	while (*str)
	{
		if (*str == ' ')
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		str++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: pointer type char
 * Return: pointer to the given string or Null on fails or str = null | ""
 */
char **strtow(char *str)
{
	int i, j, word_cnt = 0, word_idx = 0, word_start = 0, is_word = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_cnt = count_words(str);
	if (word_cnt == 0)
		return (NULL);

	words = malloc((word_cnt + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (is_word)
			{
				words[word_idx] = malloc((i - word_start + 1) * sizeof(char));
				if (words[word_idx] == NULL)
				{
					for (j = 0; j < word_idx; j++)
						free(words[j]);
					free(words);
					return (NULL);
				}

				strncpy(words[word_idx], str + word_start, i - word_start);
				words[word_idx][i - word_start] = '\0';
				word_idx++;
				is_word = 0;
			}
		}
		else if (!is_word)
		{
			word_start = i;
			is_word = 1;
		}
	}

	/* Handle the last word */
	if (is_word)
	{
		words[word_idx] = malloc((strlen(str + word_start) + 1) * sizeof(char));
		if (words[word_idx] == NULL)
		{
			for (j = 0; j <= word_idx; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		strcpy(words[word_idx], str + word_start);
		word_idx++;
	}
	words[word_idx] = NULL;

	return (words);
}
