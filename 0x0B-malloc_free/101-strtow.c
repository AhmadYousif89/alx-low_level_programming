#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_words - Free the memory allocated for words array
 * @words: array of strings
 * @word_idx: index to free up to
 */
void free_words(char **words, int word_idx)
{
	int i;

	for (i = 0; i < word_idx; i++)
		free(words[i]);
	free(words);
}

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
	int i, word_idx = 0, word_start = 0, word_len = 0;
	char **words;

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (i > word_start)
			{
				word_len = i - word_start;
				words[word_idx] = malloc((word_len + 1) * sizeof(char));
				if (words[word_idx] == NULL)
				{
					free_words(words, word_idx);
					return (NULL);
				}
				strncpy(words[word_idx], str + word_start, word_len);
				words[word_idx++][word_len] = '\0';
			}
			word_start = i + 1;
		}
	}
	if (i > word_start) /* Handle last word in (str) */
	{
		word_len = i - word_start;
		words[word_idx] = malloc((word_len + 1) * sizeof(char));
		if (words[word_idx] == NULL)
		{
			free_words(words, word_idx);
			return (NULL);
		}
		strncpy(words[word_idx], str + word_start, word_len);
		words[word_idx][word_len] = '\0';
		word_idx++;
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
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_cnt = count_words(str);
	if (word_cnt == 0)
		return (NULL);

	words = split_words(str, word_cnt);
	return (words);
}
