#include "main.h"

/**
 * get_precision - Extracts the precision for non-custom conversion specifiers.
 * @format: Formatted string.
 * @i: Pointer to the current position in the format string.
 * @list: List of arguments.
 *
 * Return: The extracted precision or -1 if not found.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;
	curr_i++;

	while (format[curr_i] >= '0' && format[curr_i] <= '9')
	{
		precision = (precision * 10) + (format[curr_i] - '0');
		curr_i++;
	}

	if (format[curr_i] == '*')
	{
		curr_i++;
		precision = va_arg(list, int);
	}

	*i = curr_i - 1;

	return (precision);
}
