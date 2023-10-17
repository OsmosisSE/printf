#include "main.h"

/**
 * print_pointer_address - prints the value of a pointer
 *in a readable hexadecimal format
 *
 * @args: list of arguments
 *
 * Return: number of printed characters
*/

int print_pointer_address(va_list args)
{
	int i, j = BUFF_SIZE - 2; /* i-length(address), j-index(addres) */
	void *p = va_arg(args, void *);
	unsigned long p_address;
	char buffer[BUFF_SIZE];
	char hex[] = "0123456789abcdef";

	if (!p)
		return (write(1, "(null)", 6));

	p_address = (unsigned long)p;

	for (i = 2; p_address > 0; i++)
	{
		buffer[j--] = hex[p_address % 16];
		p_address = p_address / 16;
	}

	j++;

	buffer[--j] = 'x';
	buffer[--j] = '0';

	return (write(1, buffer, i));
}
