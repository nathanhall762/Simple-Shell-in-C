#include "main.h"

/**
* main - entry point
* @ac: number of args
* @av: array of args
*
* Return: 0
*/
int main(int ac, char **av)
{
	(void)ac;
	int exe;
	char *buffer = NULL;
	char **cmd = NULL;

	while (1) /* while loop always happens */
	{
		signal(SIGINT, sighand); /* make sure SIGINT doesn't terminate loop */
		buffer = prompt(); /* getline in func returns str and assigns to buffer */
		if (!buffer || !buffer[0])
		{
			free(buffer);
			continue;
		}

		cmd = split_string(buffer); /* returns arr of str pointers & assigns to av */

		if (cmd)
			exe = execute(cmd);
	}

	free(buffer);
	free(cmd);
	return (0);
}

/**
* prompt - prints $ to stdout and gets input from user
*
* Return: string entered by user
*/
char *prompt(void)
{
	char *ps = "$ ";
	char *buffer = NULL;
	size_t bufsize = 0;

	if (isatty(0))
		write(1, ps, _strlen(ps));

	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		if (isatty(0))
			write(0, "\n", 1);
		free(buffer);
		exit(0);
	}

	return (buffer);
}

/**
* split_string - splits string into tokens
* @str: string to split
*
* Return: array of tokens
*/
char **split_string(char *str)
{
	char **arg;
	char *token;
	unsigned int i, numTokens = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			numTokens++;

	}

	arg = malloc(sizeof(arg) * (numTokens + 2));
	if (!arg)
	{
		perror("arg malloc Error");
		return (NULL);
	}

	token = strtok(str, " \n ");
	for (i = 0; i < (numTokens + 1); i++)
	{
		arg[i] = token;
		token = strtok(NULL, " \n ");
	}
	arg[i] = NULL;

	if (!arg[0])
	{
		free(arg);
		arg = NULL;
	}

	return (arg);
}

/**
* execute - executes array of command tokens
* @cmd: array of cmd tokens
*
* Return: 0 if success, -1 on fail
*/
int execute(char **cmd)
{
	int x;
	pid_t child = fork();

	if (child == 0)
		execve(cmd[0], cmd, environ);

	if (child == -1)
		perror("Fork Failure");

	waitpid(child, &x, 0);
	x = WEXITSTATUS(x);
	return (x);
}
