#include "main.h"

/**
 * bin_check - checks sandbox binaries for a command
 * @av: command line arguments
 * Return: char*
 */

char *bin_check(char **av)
{
	struct stat st;
	int i;
	char *new;
	char *bins[] = {"/usr/local/sbin/",
			"usr/local/bin/",
			"/usr/bin/",
			"/usr/sbin/",
			"/sbin/",
			"/bin/",
			NULL};

	for (i = 0; bins[i]; i++)
	{
		new = str_smash(av[0], bins[i]);
		if (!new)
			break;

		if (stat(new, &st) == 0)
			return (new);
	}

	return (av[0]);
}
