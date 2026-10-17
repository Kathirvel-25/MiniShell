#include "shell.h"
#include "helper.h"
#include "executer.h"
#include "signal.h"


static void handle_signal(int signo)
{
    
    if(signo == SIGINT) printf("Ctrl + c Pressed\n");
    else if(signo == SIGTERM) printf("Caugth SIGTERM\n");
    exit(EXIT_SUCCESS);
}

void Shell_main(void)
{
    char *input = NULL;
    size_t input_size = 0;

    char *token[1024];

    if(signal(SIGINT, handle_signal)  == SIG_ERR)
    {
        perror("Error: SIGINT cant handle\n");
        exit(-1);
    }
    if(signal(SIGTERM, handle_signal) == SIG_ERR)
    {
        perror("Error: SIGTERM cant handle\n");
        exit(-1);
    }

    char *home = getenv("HOME");

    if(home == NULL || chdir(home) == -1) 
    {
        perror("Error: Home directory failed\n");
        exit(1);
    }

    while(1)
    {
        int redirect = 0;

        char cwd[1024];

        if((getcwd(cwd, sizeof(cwd))) == NULL)
        {
            perror("Error: Fetching the current directory\n");
            exit(1);
        }

        printf("[My_Shell]--> (~%s)$: ", cwd);

        if(getline(&input, &input_size, stdin) == -1)
        {
            perror("Exit");
            break;
        } 

        input[my_strcspn(input, "\n")] = '\0';

        int idx = 0;

        char *temp = my_strok(input, " ");

        while(temp != NULL && idx < 1024)
        {
            token[idx++] = temp;
            temp = my_strok(NULL, " ");
        }

        token[idx] = NULL;

        

        for(int i = 0; token[i] != NULL; i++)
        {
            if(my_strcmp(token[i], ">") == 0) 
            {
                redirect = 1;
                break;
            }

            if(my_strcmp(token[i], "|") == 0)
            {
                redirect = 2;
                break;
            }
        }

        if(redirect == 1) func_dup(idx, token);
        else if(redirect == 2) pipes(idx, token);
        else shell_builts(token);
    }
}

int main(void)
{

    Shell_main();

    return 0;

}
