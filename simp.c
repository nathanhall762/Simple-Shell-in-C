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
		print("($) ");

		getline(&buf, &bufsize, stdin);

		if (strcmp(bufr, "exit\n") == 0)
			break;

		cmd = getav(bufr);

		if (execute(cmd) == -1)
			break;

	}
	free(bufr);
	free(av);
	return (0);
}