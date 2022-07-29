#include "main.h"

/**
 * funkyfresh - executes builtins
 * @arg: argument to be checked
 * Return: 0
 */

int _funkyfresh(char *arg, char **buff)
{
	unsigned int x = 0;

	if (_strcmp(arg, "exit") == 0)
	{
		x = 1;
		_scoot(arg, buff);
	}

	if (_strcmp(arg, "env") == 0)
	{
		x = 2;
		_env();
	}

	return (x);
}

/**
* _getenv - prints environment to stdout
*/

void _env(void)
{
	int i, j;
	char *str = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{	
			str = (&(environ[i][j]));
			write(1, str, _strlen(str));
			break;
		}
		_putchar(10);
	}
}

void _scoot(char *arg, char **buff)
{
	unsigned int i;

	if (buff)
	{
		for (i = 0; buff[i] && buff; i++)
			free(buff[i]);

		free(buff);
	}

	if (arg)
		free(arg);

	exit(0);
}
