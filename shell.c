#include "shell.h"
/**
 * main - This is the hub of the program
 * @ac: argc
 * @av: argv
 * @env: environ variable
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		launch_prompt(av, env);

	return (0);
}
