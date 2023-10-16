#include "main.h"

/**
 * print_exclusive_string - prints a string with ASCII
 * @format: arguments.
 * Return: the string length
 */
int print_exclusive_string(const char *format, ...)
{
	va_list args;
	char *s;
	int i, len = 0;
	int cast;

	va_start(args, format);
	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_hex_helper(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	va_end(args);
	return (len);
}
