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
	char  error_msg[] = "./shell: No such file or directory\n";
	int err_msg_length = sizeof(error_msg) - 1;

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


		args[0] = input_string;
                child_pid = fork();
                if (child_pid == -1)
                {
                        free(input_string);
                        exit(EXIT_FAILURE);
                }

		if (child_pid == 0)
		{
			if (execve(args[0],args,env) == -1)
			/*printf("%s: No such file or directory\n", av[0]);*/
				write(STDOUT_FILENO, error_msg, err_msg_length);
		}
		else
			wait(&status);
	}
}
