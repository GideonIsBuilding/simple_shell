#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void launch_prompt(char **av, char **envv) __attribute__((unused));
char *reading_input(void);
void exec_cmd(char *input_string, char **args, char **env);
int cmp_chars(char str[], const char *delim);
int str_len(const char *s);
char *str_tok(char *str, const char *delim);



#endif

