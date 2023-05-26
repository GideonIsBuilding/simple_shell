#include "shell.h"

/**
 * launch_prompt - Run the shell loop
 * @av: argv
 * @env: environment variable
 * Return: void
 */


void launch_prompt(char **av, char **env)
{
	int i;
	char *input_string = NULL;
	char *args[] = {NULL, NULL};

	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /*solves for interactive use*/
			write(STDOUT_FILENO, "#cisnotfun$ ", 12);
		input_string = reading_input();

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
		exec_cmd(input_string, args, env);

	}
}
