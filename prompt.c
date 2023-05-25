#include "shell.h"

/**
 * launch_prompt - Run the shell loop
 * @av: argv
 * @env: environment variable
 * Return: void
 */


void launch_prompt(char **av, char **env)
{

        char *input_string = NULL;
        int i,status;
        size_t n = 0;
        ssize_t num_char;
        char *args[] = {NULL, NULL};
        pid_t child_pid;


        while (1)
        {


                if (isatty(STDIN_FILENO)) /*solves for interactive use*/
                /*printf("cisnotfun$ ");*/
                        write(STDOUT_FILENO, "#cisfun$ ", 9);

                num_char = getline(&input_string, &n, stdin);
                if (num_char == -1)
                {
                        free(input_string);
                        exit(EXIT_FAILURE);

                }

                i = 0;
                while (input_string[i]) /* (input_string !==NULL*/
                {
                        if (input_string[i] == '\n')
                        {
                                input_string[i] = '\0';
                        }

                        i++;
                }







