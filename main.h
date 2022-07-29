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

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _putchar(char c);

int prompt(void);
char **split_string(char *str);
int execute(char **cmd);
void sighand(int sig);
int builtins(char *cmd);
void env(void);
void free_grid(char **grid);

int prompt(void);
char **split_string(char *str);
int execute(char **cmd);
void sighand(int sig);
char *bin_check(char **av);
char *str_smash(char *str1, char *str2);
void _env(void);
int _funkyfresh(char *arg, char **cmd);
void _scoot(char *arg, char **buff);

char **cmd;

#endif /* MAIN_H */
