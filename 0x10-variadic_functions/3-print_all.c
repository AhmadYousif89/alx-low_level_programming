#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char *const format, ...)
{
	va_list li;
	int i = 0;
	char *s;
	char *separator = "";

	va_start(li, format);

	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(li, int));
			break;
		case 'i':
			printf("%s%d", separator, va_arg(li, int));
			break;
		case 'f':
			printf("%s%f", separator, va_arg(li, double));
			break;
		case 's':
			s = va_arg(li, char *);
			if (!s)
				s = "(nil)";
			printf("%s%s", separator, s);
			break;
		default:
			i++;
			continue;
		}
		separator = ", ";
		i++;
	}

	va_end(li);
	printf("\n");
}
