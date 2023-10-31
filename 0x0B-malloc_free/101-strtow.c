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
 * split_words - Splits a string into words.
 * @str: pointer type char
 * @wc: word count
 * Return: pointer to the given string or Null on fails or str = null | ""
 */
char **split_words(char *str, int wc)
{
	int i, j, word_idx = 0, word_start = 0, is_word = 0;
	char **words;

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ') /* If the current char is empty space */
		{
			if (is_word) /* and we have a word */
			{			 /* Allocate space for that word */
				words[word_idx] = malloc((i - word_start + 1) * sizeof(char));
				if (words[word_idx] == NULL) /* Allocation failed */
				{
					for (j = 0; j < word_idx; j++)
						free(words[j]);
					free(words);
					return (NULL);
				}
				/* Copy the word to the string */
				strncpy(words[word_idx], str + word_start, i - word_start);
				/* Add null char after every word */
				words[word_idx][i - word_start] = '\0';
				word_idx++;
				is_word = 0;
			}
		}
		else if (!is_word) /* Current position is not empty space */
		{
			word_start = i; /* Word start at the current pos of (i) */
			is_word = 1;	/* Mark that we have a word */
		}
	}

	words[word_idx] = NULL;
	return (words);
}

/**
 * strtow - Splits a string into words.
 * @str: pointer type char
 * Return: pointer to the given string or Null on fails or str = null | ""
 */
char **strtow(char *str)
{
	int word_cnt = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_cnt = count_words(str);
	if (word_cnt == 0)
		return (NULL);

	return (split_words(str, word_cnt));
}
