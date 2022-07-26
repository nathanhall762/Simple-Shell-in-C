#include "main"

char *bin_check(char **av)
{
	struct stat st;
	int i = 0;
	char *new;
	char **bins = {"/usr/local/sbin/",
			"usr/local/bin/",
			"/usr/bin/",
			"/usr/sbin/",
			"/sbin/",
			"/bin/"}

	while (bins)
	{
		new = strcat(av[0], bins[i]);

		if (stat(new, &st) == 0)
			return (new);
		i++;
	}

	return (av[0]);
}
