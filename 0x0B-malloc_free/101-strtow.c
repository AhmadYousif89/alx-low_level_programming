#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * is_special - Checks for special characters
 * @c: char
 * Return: bool
 */
bool is_special(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
}

/**
 * count_words - Track the word count in a given string
 * @str: pointer type char
 * Return: the word count
 */
int count_words(char *str)
{
	int word_count = 0;
	bool in_word = false;

	while (*str)
	{
		if (!is_special(*str))
		{
			if (!in_word)
			{
				in_word = true;
				word_count++;
			}
		}
		else
			in_word = false;
		str++;
	}

	return (word_count);
}

/**
 * extract_word - Extract word from a given string
 * @str: pointer type char
 * Return: pointer to the given string
 */
char *extract_word(char *str)
{
	char *word_start, *word;
	int word_len = 0;

	while (is_special(*str)) /* Skip special characters */
		str++;

	word_start = str; /* The starting position of the pointer */

	/* Move the pointer to get the length of the word*/
	while (*str && !is_special(*str))
		str++;

	word_len = str - word_start;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	snprintf(word, word_len + 1, "%s", word_start);
	return (word);
}

/**
 * strtow - Splits a string into words.
 * @str: pointer type char
 * Return: pointer to the given string or Null on fails or str = null | ""
 */
char **strtow(char *str)
{
	int word_cnt = 0, word_idx = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_cnt = count_words(str);
	if (word_cnt == 0)
		return (NULL);

	words = (char **)malloc((word_cnt + 1) * sizeof(char *)); /* ptr size */
	/* Allocation failed */
	if (words == NULL)
		return (NULL);

	while (*str)
	{
		char *word = extract_word(str);
		/* Free allocated memory and return NULL if extraction fails */
		if (word == NULL)
		{
			for (int i = 0; i < word_idx; i++)
				free(words[i]);
			free(words);
			return (NULL);
		}
		words[word_idx] = word;
		word_idx++;
		/* Move to the next word */
		while (*str && !is_special(*str))
			str++;
	}

	words[word_idx] = NULL; /* Set the last element to null */

	return (words);
}
