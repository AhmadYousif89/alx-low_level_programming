#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str);
char **split_words(char *str, int wc);
void *free_words(char **words, int word_idx);

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
	int i, word_idx = 0, word_start = 0, word_length = 0;
	char **words;

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL); /* Allocation failur */

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ') /* Case we have an empty space */
		{
			if (i > word_start)
			{
				word_length = i - word_start;
				words[word_idx] = malloc((word_length + 1) * sizeof(char));
				if (words[word_idx] == NULL)
					free_words(words, word_idx); /* Free memory on alloc fail */

				strncpy(words[word_idx], str + word_start, word_length);
				words[word_idx][word_length] = '\0';
				word_idx++;
			}
			word_start = i + 1; /* Change the starting pos of the next word */
		}
	}
	if (i > word_start) /* Handle last word in (str) */
	{
		word_length = i - word_start;
		words[word_idx] = malloc((word_length + 1) * sizeof(char));
		if (words[word_idx] == NULL)
			free_words(words, word_idx); /* Free memory on alloc fail */

		strncpy(words[word_idx], str + word_start, word_length);
		words[word_idx][word_length] = '\0';
		word_idx++;
	}
	words[word_idx] = NULL; /* Set the last char as NULL */
	return (words);
}

/**
 * free_words - Free the memory allocated for words array
 * @words: array of strings
 * @word_idx: word position to free up
 * Return: NULL
 */
void *free_words(char **words, int word_idx)
{
	int i;

	for (i = 0; i < word_idx; i++)
		free(words[i]);
	free(words);

	return (NULL);
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
