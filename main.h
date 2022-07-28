#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/stat.h>

extern char **environ;

int _strlen(char *s);
int _putchar(char c);
int *prompt(void);
char **split_string(char *str);
int execute(char **cmd);
void sighand(int sig);
char *bin_check(char **av);
char *str_smash(char *str1, char *str2);
void _getenv(void);

char **cmd;

#endif /* MAIN_H */
