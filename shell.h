#ifndef SHELL_H
#define SHELL_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "helper.h"
#include "executer.h"


#define MAX_INPUT 1024

char** parse_input(char *input);
void shell_builts(char *args[]);
void display_help(void);


#endif