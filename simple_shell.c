#include "main.h"

/**
* main - entry point
* @ac: number of args
* @av: array of args
* @env: environment array
*
* Return: 0
*/
int main(int ac, char **av, char **env)
{
	char *buffer;
	char **cmd = NULL;
	struct stat st;
	int builtinflag;

	(void)ac;
	(void)av;
	(void)env;

	while (1) /* while loop always happens */
	{
		signal(SIGINT, sighand); /* make sure SIGINT doesn't terminate loop */
		buffer = prompt(); /* getline in func returns str and assigns to buffer */
		cmd = split_string(buffer); /* returns arr of str pointers & assigns to av */
		builtinflag = builtins(cmd[0]);
		if (builtinflag != 1)
		{
			if (stat(cmd[0], &st) == 0) /* check that cmd[0] exists */
			{
				if (execute(cmd) == -1)/* fork and execve with execute function */
					break;
			}
			else
				perror("");
		}
	}
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
	size_t bufsize;

	write(1, ps, _strlen(ps));
	if (getline(&buffer, &bufsize, stdin) == EOF)
	{
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
	char *buffer = strdup(str);
	char *token;
	size_t i, numTokens = 0;
	char prev;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == ' ' && prev != ' ')
			numTokens++;

		if (i > 0)
			prev = buffer[i - 1];
	}

	arg = malloc(sizeof(arg) * (numTokens + 2));
	token = strtok(buffer, " \n ");

	for (i = 0; token != NULL; i++)
	{
		arg[i] = token;
		token = strtok(NULL, " \n ");
	}

	arg[i] = NULL;
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
	pid_t child_pid;

	child_pid = fork();

	if (child_pid != 0)
	{
		wait(NULL);
		return (0);
	}

	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
/*			perror("Shell Error");*/
			return (-1);
		}
	}

	return (-1);
}
