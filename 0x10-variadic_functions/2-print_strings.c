#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Print strings with comma separator
 * @separator: pointer to string
 * @n: const positive number
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list li;
	unsigned int i;

	va_start(li, n);

	for (i = 0; i < n; i++)
	{
		char *p = va_arg(li, char *);
		printf("%s", p ? p : "(nil)");
		if (separator && i < n - 1)
			printf("%s", separator);
	}

	va_end(li);
	printf("\n");
}
