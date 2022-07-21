#include "main.h"

/**
 * main - runs a simple shell
 * Return: 0
 */

char **av;
char **getav(char *);
void print_array(char **av);
int exe(char **cmd);

int main(void)
{
	char *buf = NULL;
	char **cmd;
	size_t bufsize = 0;

	while (1)
	{
		printf("($) ");

		getline(&buf, &bufsize, stdin);

		if (strcmp(buf, "exit\n") == 0)
			break;

		cmd = getav(buf);

		if (exe(cmd) == -1)
			break;

	}
	free(buf);
	free(av);
	return (0);
}

char **getav(char *buf)
{
	char* token;
	int i = 0, numTokens = 0, len = 0;
	char prev = '0';

	while (buf[len])
	{
		if (buf[len] == ' ' && prev != ' ') //comparison between pointer and integer???
			numTokens++;
		prev = buf[len];
		len++;
	}

	token = malloc(sizeof(*av) * (numTokens + 2)); //sizeof of what???

	token = strtok(buf, " ");
	av[i] = token;
	i++;

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		av[i] = token;
		i++;
	}

	av[i] = NULL;
	return (av);
}
