#include "main.h"

/**
 * print_alphabet_x10 - print string 10x to stdio
 * Print the alphabet 10x in lowercase using for loop and putchar();
 * Return: Void
 */
void print_alphabet_x10(void)
{
	int ch;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (ch = 'a'; ch <= 'z'; ch++)
		{
			_putchar(ch);
		}
		_putchar('\n');
	}
}
