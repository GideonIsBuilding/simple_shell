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

/**
 * cmp_chars - compare chars of string
 * @str: input string
 * @delim: delim
 * Return: 1 or 0
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * str_len - Finds the length of a string
 * @s: Type char pointer
 * Return: Always 0
 */

int str_len(const char *s)
{
	int len;

	for (len = 0; *s != '\0'; ++s)
		++len;

	return (len);

}


/**
 * str_tok - this splits a string through a delim
 * @str: input command string
 * @delim: delim
 * Return: 1st string that is split
 */

char *str_tok(char *str, const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		i = str_len(str);
		str_end = &str[i];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}

