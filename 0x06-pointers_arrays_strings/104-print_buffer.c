#include <stdio.h>
#include "main.h"

/**
 * print_buffer - .
 * @b: pointer typr char *
 * @size: size of buffer type number
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i, j;
	char *buffer = b;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i); /* 00000000: | 0000000a: | etc... */
		for (j = 0; j < 10; ++j)
		{
			if (i + j < size)
			{
				printf("%02x", (unsigned char)buffer[i + j]); /* 5468 6973 2069 etc... */
				if (j % 2 == 1)
					printf(" ");
			}
			else
			{
				printf("  ");
				if (j % 2 == 1)
					printf(" ");
			}
		}
		for (j = 0; j < 10; ++j)
		{
			if (i + j < size)
			{ /* Valid range for Ascii characters [32 .. 126] */
				if (buffer[i + j] >= 32 && buffer[i + j] <= 126)
					printf("%c", b[i + j]); /* This is a etc... */
				else
					printf(".");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
