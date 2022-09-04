#ifndef SHELL_H
# define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char **argv, char **env);
void lsh_loop(void);
char *lsh_read_line(void);
char *mystrchr(const char * s, const char c);
char *str_tok(char * str, const char * delim);
char **lsh_split_line(char *line);
int lsh_execute(char **args);
int lsh_lauch(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_num_builtins();


#endif
