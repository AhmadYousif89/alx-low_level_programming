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
	char str[] = "_puchar";
	int str_len = strlen(str);
	int i = 0;

	while (i < str_len)
	{
		putchar(str[i]);
		i++;
	}
	putchar('\n');

	return (0);
}
