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

/**
 * sighand - handles sigint
 * @sig: signal
 */

void sighand(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 5);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: 0
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, n = 0;

	while (dest[i] != '\0')
		i++;

	while (src[n] != '\0')
	{
		dest[i] = src[n];
		n++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - returns pointer to memory of given string
 * @str: string
 * Return: pointer to str, null if error
 */

char *_strdup(char *str)
{
	char *dupe;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dupe = malloc(sizeof(char) * (len + 1));

	if (dupe == NULL)
		return (NULL);

	while ((dupe[i] = str[i]) != '\0')
		i++;

	return (dupe);
}

/**
 * _strcmp - compares two strings
 * @s1: char
 * @s2: char
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
