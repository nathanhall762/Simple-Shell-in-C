#include "main.h"

int builtins(char *cmd)
{
	int strcmp_result;
	char *builtin_list[] = { "env", "exit", NULL};

	if (_strcmp(cmd, builtin_list[0]) == 0)
	{
		env();
		return (1);
	}
	if (_strcmp(cmd, builtin_list[1]) == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
void env(void)
{
    unsigned int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');
		i++;
	}
}
