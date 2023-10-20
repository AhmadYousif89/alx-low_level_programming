#include <stdio.h>
#include "main.h"

/**
 * is_printable - .
 * @c: number
 * Return: int
 */
int is_printable(int c)
{
	return (c >= 32 && c <= 126);
}

/**
 * print_buffer - Print string to buffer
 * @b: pointer typr char *
 * @size: size of buffer type number
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int start, i, end;

	if (size <= 0)
		printf("\n");
	else
	{
		for (start = 0; start < size; start += 10)
		{
			printf("%.8x:", start);
			for (i = start; i < start + 10; i++)
			{
				if (i % 2 == 0)
					printf(" ");
				if (i < size)
					printf("%.2x", *(b + i));
				else
					printf("  ");
			}
			printf(" ");

			for (end = start; end < start + 10; end++)
			{
				if (end >= size)
					break;
				if (*(b + end) < 32 || *(b + end) > 126)
					printf("%c", '.');
				else
					printf("%c", *(b + end));
			}
			printf("\n");
		}
	}
}
