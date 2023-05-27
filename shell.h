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
int main(int argc, char **argv)
char *command_checker(char **tokens)
int tokenize(char *input, char **tokens, int max_tokens)
void execute(char **tokens)
char *allocate_buffer(size_t buf_size)
char *expand_buffer(char *buf, size_t buf_size)
int is_empty_line(ssize_t len, char *buf)
int handle_empty_line(char *buf, char **lineptr)
void terminate_buffer(ssize_t len, char *buf)
char *strd_up(const char *str)
int Strn_cmp(const char *s1, const char *s2, size_t n)
char *Str_cat(char *dest, const char *src)
char *Str_cpy(char *dest, const char *src)
char *concat_str(char *str1, char *str2)
int my_strcmp(const char *str1, const char *str2)
void writeStringToStderr(char *str)
int StringLength(const char *str)
void printStr(char *str)
char *reading_input()

#endif

