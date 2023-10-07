#include <stdlib.h>
#include <time.h>

/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */

/**
 * main - Entry point
 * Print all possible combination of single number using putchar();
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
    {
        putchar(i);
        if (i < '9')
            putchar(',');
		putchar(' ');
    }
	putchar('\n');
	return (0);
}
