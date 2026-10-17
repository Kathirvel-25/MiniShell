#include "shell.h"


void display_help(void)
{
    printf("\n");
    printf("Available command:\n");
    printf("\tcd <directory>     -Change the current directory.\n");
    printf("\techo <text>        -print the given text\n");
    printf("\tsetenv VAR = VALUE   -set an enviromental variables\n");
    printf("\tenv                -Display the all enviromental varaibles\n");
    printf("\tmkdir              -Make the new file\n");
    printf("\trmdir              -Remove the file that already exit\n");
    printf("\tls -flag           -view the current directory of the file\n");
    printf("\twhich <command>    -Locate the executable in the system PATH\n");
    printf("\texit               -Exit the shell\n");
    printf("\n");
    return;
}
  
void shell_builts(char *args[])
{

    if(args == NULL) return;
    else if((my_strcmp(args[0], "help")) == 0) display_help();
    else if((my_strcmp(args[0], "exit")) == 0) exit(1);
    else if((my_strcmp(args[0], "env")) == 0) display_enviroment();
    else if((my_strcmp(args[0], "mkdir")) == 0) folder_creation(args[1]);
    else if((my_strcmp(args[0], "rmdir")) == 0) remove_folder(args[1]);
    else if((my_strcmp(args[0], "ls")) == 0) show_file(args);
    else if((my_strcmp(args[0], "cd")) == 0) change_directory(args[1]);
    else if((my_strcmp(args[0], "cat")) == 0)  show_file(args);
    else if((my_strcmp(args[0], "echo")) == 0) echo(args);
    else if((my_strcmp(args[0], "setenv")) == 0) my_setenv(args[1], args[3]);
    else printf("Error: Invalid command type help for the valid command\n");
    
}
