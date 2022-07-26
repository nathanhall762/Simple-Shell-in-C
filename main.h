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
char *prompt(void);
char **split_string(char *str);
int execute(char **cmd);
void sighand(int sig);
char *bin_check(char **av);

#endif /* MAIN_H */
