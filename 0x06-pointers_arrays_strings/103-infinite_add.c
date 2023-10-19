#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * infinite_add - Add and return two numbers
 * @n1: pointer type char *
 * @n2: pointer type char *
 * @r: pointer type char *
 * @size_r: number type int
 * Return: string buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, n1_len = strlen(n1), n2_len = strlen(n2);
	int big_len = 0, cur_n1_digit = 0, cur_n2_digit = 0, acc = 0;
	char *buffer = r;

	/* Specify the bigger string to work with */
	if (n1_len > n2_len)
		big_len = n1_len;
	else
		big_len = n2_len;
	/* Check if the given string (n1 or n2) is bigger than the (size_r) */
	if (size_r < big_len + 1)
		return (0);
	/* Add the null termination character at the end of the buffer */
	buffer[big_len] = '\0';
	/* Loop over the buffer untill (big_len) = 0 */
	for (i = big_len - 1; i >= 0; i--)
	{
		n1_len--;
		n2_len--;
		/* Extract (n1) digits */
		if (n1_len >= 0)
			cur_n1_digit = n1[n1_len] - '0';
		else
			cur_n1_digit = 0;
		/* Extract (n2) digits */
		if (n2_len >= 0)
			cur_n2_digit = n2[n2_len] - '0';
		else
			cur_n2_digit = 0;
		/* Add extracted digits to the buffer */
		buffer[i] = (cur_n1_digit + cur_n2_digit + acc) % 10 + '0';
		acc = (cur_n1_digit + cur_n2_digit + acc) / 10;
	}
	/* Case we have additional leftover digit */
	if (acc == 1)
	{
		/* Move the null char 1 index forward makeing room for the digit */
		buffer[big_len + 1] = '\0';
		/* Check the (big_len) aginst the (size_r) agian */
		if (size_r < big_len + 2)
			return (0);
		/* Over write the buffer */
		while (big_len >= 0)
		{
			buffer[big_len + 1] = buffer[big_len];
			big_len--;
		}
		buffer[0] = acc + '0';
	}

	return (buffer);
}
