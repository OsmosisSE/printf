#include "main.h"

/**
 * print_pointer_addr: prints the value of a pointer
 * @args: list of arguments
 *
 * Return: number of printer characters
 */
int print_pointer_addr(va_list args)
{
	void *p = va_arg(args, void *);
	unsigned long p_address;
	char buffer[BUFF_SIZE];
	char hex[] = "0123456789abcdef";

	if (!p)
		return (write(1, "(null)", 6));

	p_address = (unsigned long)p;

	int i = 0;

	do {
		buffer[i++] = hex[p_address % 16];
		p_address = p_address / 16;
	} while (p_address > 0);

	buffer[i++] = 'x';
	buffer[i++] = '0';

	/*Reverse the string*/
	int start = 0;
	int end = i - 1;

	while (start < end) 
	{
		char temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}

	return (write(1, buffer, i));
}
