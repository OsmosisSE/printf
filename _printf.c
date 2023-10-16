#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char c;

	va_start(args, format);

	while (format && format[printed_chars])
	{
		if (format[printed_chars] != '%')
		{
			write(1, &format[printed_chars], 1);
		}
		else
		{
			printed_chars += handle_specifier(&format[printed_chars + 1], args);
		}
		printed_chars++;
	}

	va_end(args);
	return (printed_chars);
}
