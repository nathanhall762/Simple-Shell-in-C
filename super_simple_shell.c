#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *prompt(void);
char **split_string(char *str);
int execute(char **cmd);

int main(void)
{
	char **av;
	char *buffer;
	char **cmd = NULL;

	printf("========================================================\n");
	/* prints a pretty line */

	while (1) /* while loop always happens */
	{
		buffer = prompt(); /* getline in func returns str and assigns to buffer */
		cmd = split_string(buffer); /* returns arr of str pointers & assigns to av */
		if (execute(cmd) == -1)/* fork and execve with execute function */
			break;
	}
	printf("Error: shell failure: Terminating . . .\n");
	return (0);
}

char *prompt(void)
{
	char *buffer = NULL;
	size_t bufsize;

	printf("$ ");
	getline(&buffer, &bufsize, stdin);

	return (buffer);
}

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
			perror("Error: command failure");
			return (-1);
		}
	}
	return (-1);
}
