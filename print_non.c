#inclue "main.h"

/**
 * print_non - prints non printable characters
 *
 * @args: list of arguments
 *
 * Return: hex value of all the non_printable characters
*/

int print_non(va_list args)
{
	char *s = va_arg(args, char *);
	char buffer[BUFF_SIZE];
	int i, adj_index = 0;

	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 32 && s[i] < 127)
			buffer[i + adj_index] = s[i];
		else
			adj_index += create_hexa(buffer, s[i], i + adj_index);
	}

	buffer[i + adj_index] = '\0';

	return (write(1, buffer, i + adj_index));
}

/**
 * create_hexa - cerates the hexa dcimal code of characters
 *
 * @buffer: buffer array of characters
 * @ascii: ascii value
 * @i: hexa creation index in buffer
 *
 * Return: hexa code
*/

int create_hexa(char buffer[], char ascii, int i)
{
	char hexa[] = "0123456789ABCDEF";

	if (ascii < 0)
	{
		ascii *= -1; /* make ascii positive if negative*/
	}

	/* write '\x' to buffer */
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	/* write hex value to buffer */
	buffer[i++] = hexa[ascii / 16];
	buffer[i] = hexa[ascii % 16];

	return (3);
}
