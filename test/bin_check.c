#include "main.h"
<<<<<<< HEAD:test/bin_check.c
=======

/**
 * bin_check - checks sandbox binaries for a command
 * @av: command line arguments
 * Return: char*
 */
>>>>>>> 8233b62648813dbcd4226a5f9371d5c233cd82f3:bin_check.c

/**
* bin_check
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
