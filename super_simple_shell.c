#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **av;

char *prompt(void);
char **split_string(char *str);

int main(void)
{
	char *buffer;
	int i = 0;
	char **av;

	printf("=================================\n"); //prints a pretty line

	while (1) //while loop always happens
	{
		buffer = prompt(); //getline in prompt function returns string and assigns to buffer
		printf("%s", buffer); //test that buffer has the string
		av = split_string(buffer); //split_string returns array of string pointers and assigns to av
		printf("split_string success");
		while (av[i]) //test that av has the array of strings
		{
			printf("%s", av[i]);
			i++;
		}
		//fork and execve
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

char **split_string(char *buffer)
{
	char* token;
	int i = 0, numTokens = 0, len = 0;
	char prev = '0';

	while (buffer[len])
	{
		if (buffer[len] == ' ' && prev != ' ') //comparison between pointer and integer???
			numTokens++;
		prev = buffer[len];
		len++;
	}

	token = malloc(sizeof(*av) * (numTokens + 2)); //sizeof of what???

	token = strtok(buffer, " ");
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
