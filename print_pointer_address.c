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
	char *hex_address; /* pointer hex address */
	int counter = 0; /* track number of hex characters */
	unsigned long int ptr = va_arg(args, unsigned long int);

	if (!ptr)
		return (write(1, "(null)", 6));

	hex_address = get_pointer_value(ptr);

	counter = 2 + _strlen(hex_address);

	write(1, "0x", 2);
	write(1, &hex_address, counter - 2);


	return (counter);
}

/**
 * get_pointer_value - gets the value of a pointer in hex fmt
 *
 * @pointer: pointer to consider
 *
 * Return: pointer value in hex format
*/
char *get_pointer_value(unsigned int pointer)
{
	char *p_address, buffer[BUFF_SIZE];
	char hexa[] = "0123456789abcdef";

	p_address = &buffer[BUFF_SIZE - 1];
	*p_address = '\0';

	/* pointer address[] is filled from the last element*/
	for (; pointer != 0; pointer /= 16)
		*--p_address = hexa[pointer % 16];

	return (p_address);
}
