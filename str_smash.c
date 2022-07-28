#include "main.h"

/**
 * str_smash - concats two strings
 * @str1: string 1
 * @str2: string 2 
 * Return: char*
 */

char *str_smash(char *str1, char *str2)
{
	unsigned int i, j;
	char *new = malloc(sizeof(str1) + sizeof(str2));

	if (!new || !str1 || !str2)
	{
		free(new);
		exit(0);
	}

	for (i = 0; str1[i]; i++)
	{
		new[i] = str1[i];

		if (!str1[i])
		{
			for (j = 0; str2[j]; j++)
			{
				i++;
				new[i] = str2[j];
			}
		}
	}

	return (new);
}
