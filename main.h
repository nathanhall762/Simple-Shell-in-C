#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/stat.h>

int _strlen(char *s);
int _putchar(char c);
char *prompt(void);
char **split_string(char *str);
int execute(char **cmd);

#endif /* MAIN_H */
