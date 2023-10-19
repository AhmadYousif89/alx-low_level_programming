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

	if (n1_len > n2_len)
		big_len = n1_len;
	else
		big_len = n2_len;
	if (size_r < big_len + 1)
		return (0);
	buffer[big_len] = '\0';
	for (i = big_len - 1; i >= 0; i--)
	{
		n1_len--;
		n2_len--;
		if (n1_len >= 0)
			cur_n1_digit = n1[n1_len] - '0';
		else
			cur_n1_digit = 0;
		if (n2_len >= 0)
			cur_n2_digit = n2[n2_len] - '0';
		else
			cur_n2_digit = 0;
		buffer[i] = (cur_n1_digit + cur_n2_digit + acc) % 10 + '0';
		acc = (cur_n1_digit + cur_n2_digit + acc) / 10;
	}
	if (acc == 1)
	{
		buffer[big_len + 1] = '\0';
		if (size_r < big_len + 2)
			return (0);
		while (big_len >= 0)
		{
			buffer[big_len + 1] = buffer[big_len];
			big_len--;
		}
		buffer[0] = acc + '0';
	}

	return (buffer);
}
