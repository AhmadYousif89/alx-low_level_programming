#include <stdlib.h>
#include <time.h>

/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */

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
