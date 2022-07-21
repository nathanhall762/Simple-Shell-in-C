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
	char *buffer;
	char **cmd = NULL;

	printf("========================================================\n"); //prints a pretty line

	while (1) //while loop always happens
	{
		{
			buffer = prompt(); //getline in prompt function returns string and assigns to buffer
			cmd = split_string(buffer); //returns array of string pointers and assigns to av
			if (execute(cmd) == -1)//fork and execve with execute function
				break;
		}
	}
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
	char *buffer = strdup(str);
	char *token;
	int i = 0, numTokens = 0;
	char prev = '0';
	char **av;

	while (buffer[i])
	{
		if (buffer[i] == ' ' && prev != ' ')
			numTokens++;
		prev = buffer[i];
		i++;
	}

	av = malloc(sizeof(*av) * (numTokens + 2));

	token = strtok(buffer, " \n");
	av[0] = token;
	i = 1;

	while (token != NULL)
	{
		token = strtok(NULL, " \n");
		av[i] = token;
		i++;
	}

	av[i] = NULL;
	return (av);
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
			perror("Error");
			return (-1);
		}
	}
	return (-1);
}
