#include <stdio.h>
#include "main.h"
/**
 * main - Entry point
 * Run the function print_alphabet()
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_alphabet();
	return (0);
}

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
		putchar(ch);
	}
	putchar('\n');
}
