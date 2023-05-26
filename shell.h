#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void launch_prompt(char **av, char **envv);
char *reading_input(void);
void exec_cmd(char *input_string, char **args, char **env);



#endif

