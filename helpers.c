#include "main.h"

/**
 * _strlen - calculates the length of a string
 * 
 * @s: string to be considered
 * 
 * Return: length of a string
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
