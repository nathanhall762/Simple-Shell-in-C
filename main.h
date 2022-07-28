#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/stat.h>
#include <dirent.h>

extern char **environ;

int _strlen(char *s);
int _putchar(char c);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char **split_string(char *str);
int execute(char *env, char **cmd);
void sighand(int sig);
char *bin_check(char **av);
char *str_smash(char *str1, char *str2);
char **_getenv(char *str);
char **_envtok(char *env);
char *map(char **cmd, char **trail);

#endif /* MAIN_H */
