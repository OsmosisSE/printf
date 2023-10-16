#include "main.h"
/**
 * print_reversed - prints a reversed string
 * @args: list of arguments
 * Return: the reversed string
 */
int print_reversed(va_list args)
{
	int length;
	char *string;
	char *ptr;

	string = va_arg(args, char *);
	ptr = rev_string(string);
	if (string == NULL || ptr == NULL)
		return (-1);
	for (length = 0; ptr[length] != '\0'; length++)
		_putchar(ptr[length]);
	free(ptr);
	return (length);
}
/**
 * print_rot13 - prints the rot13'ed string
 * @args: strings to be rot13'ed
 * Return: converted string
 */
int print_rot13(va_list args)
{
	int a, b;
	char *string;
	char c[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char d[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(args, char *);
	if (string == NULL)
		return (-1);
	for (a = 0; string[a] != '\0'; a++)
	{
		for (b = 0; b <= 52; b++)
		{
			if (string[a] == c[b])
			{
				_putchar(d[b]);
				break;
			}
		}
		if (b == 53)
			_putchar(string[a]);
	}
	return (a);
}
