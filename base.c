#include "main.h"

/**
 * print_binary - Converts a number from decimal to binary
 * @args: List of arguments
 * Return: The length of the number printed
 */
int print_binary(va_list args)
{
	unsigned int num;
	int i, n_len;
	char *str;
	char *r_str;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	n_len = base_len(num, 2);
	str = malloc(sizeof(char) * (n_len + 1));
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num /= 2;
	}
	str[i] = '\0';
	r_str = rev_string(str);
	if (r_str == NULL)
	{
		free(str);
		return (-1);
	}
	write_base(r_str);
	free(str);
	free(r_str);
	return (n_len);
}

/**
 * print_octal - Prints the numeric representation of a number in base 8
 * @args: list of all the arguments passed to the program
 * Return: len
*/
int print_octal(va_list args)
{
	int len;
	unsigned int num;
	char *octal;
	char *r_str;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	octal = malloc(sizeof(char) * (len + 1));
	if (octal == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal[len] = (num % 8) + 48;
		num /= 8;
	}
	octal[len] = '\0';
	r_str = rev_string(octal);
	if (r_str == NULL)
		return (-1);

	write_base(r_str);
	free(octal);
	free(r_str);
	return (len);
}

/**
 * hex_check - checks which hexadecimal function calling it
 * @num : integer to be converted to characters
 * @x: tells which hex function is calling it
 * Return: ASCII value for a character
*/
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *heX = "ABCDEF";

	num -= 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (heX[num]);
	return (0);
}

/**
 * print_hex - Prints a representation of a decinal number in base 16 lowercase
 * @args: List of arguments passed to the function
 * Return: Number of characters printed
*/
int print_hex(va_list args)
{
	unsigned int num;
	int len, n_num;
	char *hex_rep;
	char *r_str;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * (len + 1));
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		n_num = num % 16;
		if (n_num > 9)
		{
			n_num = hex_check(n_num, 'x');
			hex_rep[len] = n_num;
		}
		else
			hex_rep[len] = n_num + 48;
		num /= 16;
	}
	hex_rep[len] = '\0';
	r_str = rev_string(hex_rep);
	if (r_str == NULL)
		return (-1);
	write_base(r_str);
	free(hex_rep);
	free(r_str);
	return (len);
}


/**
 * print_heX - Prints a representation of a decinal number in base 16 uppercase
 * @args: List of arguments passed to the function
 * Return: Number of characters printed
*/
int print_heX(va_list args)
{
	unsigned int num;
	int len, n_num;
	char *hex_rep;
	char *r_str;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * (len + 1));
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		n_num = num % 16;
		if (n_num > 9)
		{
			n_num = hex_check(n_num, 'X');
			hex_rep[len] = n_num;
		}
		else
			hex_rep[len] = n_num + 48;
		num /= 16;
	}
	hex_rep[len] = '\0';
	r_str = rev_string(hex_rep);
	if (r_str == NULL)
		return (-1);
	write_base(r_str);
	free(hex_rep);
	free(r_str);
	return (len);
}
