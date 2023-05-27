#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

void launch_prompt(char **av, char **envv) __attribute__((unused));
char *reading_input(void);
void exec_cmd(char *input_string, char **args, char **env);
int cmp_chars(char str[], const char *delim);
int str_len(const char *s);
void free_char_array(char **args);
char *str_tok(char *str, const char *delim);
ssize_t my_getline(char **lineptr, size_t *n, int fd)



#endif

