#include <stdlib.h>
#include <time.h>

/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */

/**
 * main - Entry point
 * Print the alphabet reversed using putchar();
 * Return: Always 0 (Success)
 */

int main(void)
{
	char ch;

	for (ch = 'z'; ch >= 'a'; ch--)
		putchar(ch);
	putchar('\n');
	return (0);
}
