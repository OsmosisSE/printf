#include "main.h"

/**
 * print_number - prints a number used as an argument
 * @args: list of arguments
 * Return: The total of the arguments printed
 */
int print_number(va_list args)
{
	int n, div, n_len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	n_len = 0;

	if (n < 0)
	{
		n_len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; (num / div) > 9; )
		div *= 10;

	for (; div != 0; )
	{
		n_len += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	return (n_len);
}

/**
 * print_unsigned_int - prints an unsigned int
 * @n: unsigned int to be printed
 * Return: The total of the number printed
 */
int print_unsigned_int(unsigned int n)
{
	int div, n_len;
	unsigned int num;

	div = 1;
	n_len = 0;

	num = n;

	for (; (num / div) > 9; )
		div *= 10;

	for (; div != 0; )
	{
		n_len += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}

	return (n_len);
}
