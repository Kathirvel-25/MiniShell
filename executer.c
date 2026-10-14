#include "executer.h"

extern char** environ;

void display_enviroment(void)
{
    char** ev;
    printf("\n");
    for(ev = environ; *ev != NULL; ev++)
    {
        printf("%s\n", *ev);
    }
    printf("\n");
}



void folder_creation(char *name)
{
    if(mkdir(name, 0777) == -1)
    {
        perror("Error: Folder creation error\n");
        return;
    }
    printf("Folder creation succesfully\n");
}



void remove_folder(char *args)
{
    if(rmdir(args) == -1)
    {
        printf("Error: failed to remove '%s': No such file or directory\n", args);
        return;
    }
}



void show_file(char* args[])
{
       pid_t pid = fork();

       if(pid == -1)
       {
            perror("Error: creating the process\n");
            exit(1);
       }
       
       if(pid == 0)
       {
            printf("\n");

            execvp(args[0], args);

            perror("Error: listing the directorys\n");
            return;
       }

       else waitpid(pid, NULL, 0);

       printf("\n");
       
}


void change_directory(char *dir)
{
    if(chdir(dir) == -1)
    {
        perror("Error: No such directory\n");
        return;
    }
}

void func_dup(int idx, char *token[])
{

    int direct = 0;

    for(int i = 0; token[i] != NULL; i++)
    {
        if(my_strcmp(token[i], ">") == 0)
        {
            direct = i;
            break;
        }
    }

    if(direct <= 0 || direct + 1 >= idx || direct + 2 != idx || direct == idx)
    {
        perror("Error: invalid command\n");
        return;
    }

    char *file = token[direct + 1];

    token[direct] = NULL;

    pid_t pid = fork();

    if(pid == -1)
    {
        perror("Error: Process creaiton\n");
        return;
    }

    if(pid == 0)
    {
        int fd = open(file, O_WRONLY | O_CREAT| O_TRUNC, 0644);

        if(fd == -1)
        {
            perror("Error: File creation\n");
            exit(1);
        }

        if(dup2(fd, STDOUT_FILENO) == -1)
        {
            perror("Error: dup2");
            close(fd);
            exit(1);
        }

        close(fd);

        execvp(token[0], token);

        perror("Error: execvp\n");
        exit(-1);

    }

    else waitpid(pid, NULL, 0);
}