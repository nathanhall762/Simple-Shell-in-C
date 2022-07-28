#include "main.h"

int main(int ac, char **av)
{
	av[0] = "/usr/bin/which";

	execve(av[0], av, NULL);

	return (-1);
}