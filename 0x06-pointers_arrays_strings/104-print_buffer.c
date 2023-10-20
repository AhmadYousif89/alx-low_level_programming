#include <stdio.h>
#include "main.h"

/**
 * is_printable - Check if given char is a valid printable Ascii
 * @c: char
 * Return: int
 */
int is_printable(char c)
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
	int start, i, j;

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

			for (j = start; j < start + 10; j++)
			{
				if (j >= size)
					break;
				if (is_printable(*(b + j)))
					printf("%c", *(b + j));
				else
					printf(".");
			}
			printf("\n");
		}
	}
}
