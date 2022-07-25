#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: char
 * Return: string length
 */

int _strlen(char *s)
{
	int str = 0;

	while (*s++)
		str++;

	return (str);
}