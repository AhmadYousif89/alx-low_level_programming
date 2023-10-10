#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * main - Entry point
 * Print string "_putchar" using while loop and putchar();
 * Return: Always 0 (Success)
 */
int main(void)
{
	char str[] = "_putchar";
	int str_len = strlen(str);
	int i = 0;

	while (i < str_len)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
