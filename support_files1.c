#include "shell.h"

/**
 * reading_input - reads input from user
 * Return: returns the input as a string
 */

char *reading_input()
{
	char *input_string = NULL;
	size_t n = 0;
	ssize_t num_char;

	num_char = getline(&input_string, &n, stdin);
	if (num_char == -1)
	{
		free(input_string);
		exit(EXIT_FAILURE);
	}

	return (input_string);

}

/**
 * exec_cmd - This creates a child process and executes command
 * @input_string: the input command
 * @args: arguments 2D array for commands
 * @env: env
 * Return:Void
 */

void exec_cmd(char *input_string, char **args, char **env)
{
	int status;
	pid_t child_pid;
	char error_msg[] = "./shell: No such file or directory\n";
	int err_msg_length = sizeof(error_msg) - 1;


	child_pid = fork();
	if (child_pid == -1)
	{
		free(input_string);
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
			write(STDOUT_FILENO, error_msg, err_msg_length);
	}
	else
		wait(&status);
}


