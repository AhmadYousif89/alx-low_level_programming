#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - .
 * @format: pointer to string
 * Return: Nothing
 */
void print_all(const char *const format, ...)
{
	va_list args;
	int i = 0;
	char *str;

	va_start(args, format);

	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%c ", va_arg(args, int));
			break;
		case 'i':
			printf("%d ", va_arg(args, int));
			break;
		case 'f':
			printf("%f ", va_arg(args, double));
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s ", str);
			break;
		default:
			break;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
