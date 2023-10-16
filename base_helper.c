#include "main.h"

/**
 * rev_string - reverses an input string
 * @s: string to reverse
 *
 * Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int len, head;
	char t;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		t = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = t;
	}
	return (dest);
}

/**
 * write_base - sends characters to be written to standard output
 * @str: String to parse
 */
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * base_len - Calculates the length for a number
 * @num: The number for which the length is being calculated
 * @base: Specified base
 * Return: the length of the number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * _memcpy - fuction that copies memeory area
 * @dest: destination
 * @src: source
 * @n: number of bytes to copy
 * Return: returns a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
