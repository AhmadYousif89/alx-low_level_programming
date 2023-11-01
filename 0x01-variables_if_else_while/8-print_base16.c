#include <stdlib.h>
#include <stdio.h>

/**
 * main - Entry point
 * Print all the numbers of base 16 in lowercase using putchar();
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	char ch;

	for (i = '0'; i <= '9'; i++)
		putchar(i);
	for (ch = 'a'; ch < 'g'; ch++)
		putchar(ch);
	putchar('\n');
	return (0);
}
