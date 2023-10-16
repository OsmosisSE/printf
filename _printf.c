#include "main.h"

/**
 * _printf - receives input with parameters and print a formatted string
 * @format: string for formatting input
 *
 * Return: The total of character printed
 */
int _printf(const char *format, ...)
{
	int result;
	conver_t func[] = {{"c", print_char}, {"s", print_string},
	{"%", print_percent}, {"d", print_int}, {"i", print_int},
	{"u", unsigned_int}, {"b", print_binary}, {"o", print_octal},
	{"x", print_hex}, {"X", print_heX}, {"r", print_reversed},
	{"R", print_rot13}, {NULL, NULL}};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	result = process(format, func, args);
	va_end(args);
	return (result);
}
