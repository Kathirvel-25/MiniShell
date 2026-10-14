#ifndef EXECUTER_H
#define EXECUTER_H

#include "stdio.h"
#include "sys/stat.h"
#include "sys/wait.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdlib.h"
#include "helper.h"




void display_enviroment(void);
void folder_creation(char *name);
void remove_folder(char *args);
void show_file(char* args[]);
void change_directory(char *dir);
void my_cat(char *file);
void func_dup(int idx, char *token[]);


#endif