#include <stdio.h>
#include "main.h"
/**
 * print_alphabet - print string to stdio
 * Print the alphabet in lowercase using for loop and putchar();
 * Return: Void
 */
void print_alphabet(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}
