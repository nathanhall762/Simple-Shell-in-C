#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char **av;
char **getav(char *);
void print_array(char **av);
int exe(char **cmd);

#endif /* MAIN_H */