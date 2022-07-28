#include "main.h"

/**
 * _getenv - checks path for command
 * @env: PATH
 * Return: env of command on success, otherwise NULL
 */

char **_getenv(char *env)
{
	unsigned int i, j;
	char *strenv = NULL;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env[j])
				break;

			if (environ[i][j] == env[j])
			{
				if (env[j + 1] == '\0' && environ[i][j + 1] == '=')
					return (_envtok(&(environ[i][j + 2])));
			}
		}
	}
	return (NULL);
}

/**
 * _envtok - creates tokens from env
 * @str: input env string
 * Return: env or NULL
 */

char **_envtok(char *str)
{
	unsigned int i, j, numTokens = 0;
	char **env;
	char *token;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ':')
			numTokens++;
	}

	env = malloc(sizeof(env) * (numTokens + 3));
	if (!env)
	{
		perror("arg malloc Error");
		return (NULL);
	}

	token = strtok(str, " \n ");
	for (i = 0; i < (numTokens + 1); i++)
	{
		env[i] = token;
		token = strtok(NULL, ":");
	}
	env[i + 1] = NULL;

	if (!env[0] || !env)
	{
		free(env);
		env = NULL;
	}

	return (env);
}

/**
 * 
 * 
 * 
 */

char *map(char **cmd, char **trail)
{
	struct dirent *bank;
	DIR *dir;
	unsigned int i;
	char *tmp = NULL;

	if (cmd[0][0] == '/')
		return (cmd[0]);

	for (i = 0; trail[i]; i++)
	{
		dir = opendir(trail[i]);
		if (dir)
		{
			while ((bank = readdir(dir)))
			{
				if (_strcmp(cmd[0], bank->d_name) == 0)
				{
					closedir(dir);
					return (_strcat(_strcat(trail[i], "/"), cmd[i]));
				}
			}
		}
		closedir(dir);
	}
	return (NULL);
}
