#include "main.h"
/**
 * print_char - Prints character
 * @args: list of arguments
 *
 * Return: return the total of characters printed
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @args: list of arguments
 *
 * Return: returns the total of characters printed
 */
int print_string(va_list args)
{
	int i;
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @args: list of arguments
 *
 * Return: returns the total of characters printed
 */
int print_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * print_int - Prints an interger
 * @args: list of arguments
 *
 * Return: returns the total of characters printed
 */
int print_int(va_list args)
{
	int n_len;

	n_len = print_number(args);
	return (n_len);
}

/**
 * unsigned_int - Prints unsigned integers
 * @args:list of arguments
 *
 * Return: returns the total of characters printed
 */
int unsigned_int(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsigned_int(num));
	if (num < 1)
		return (-1);
	return (print_unsigned_int(num));
}
