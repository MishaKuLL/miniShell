#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_data
{
    char	cmd;
}	t_data;


void	free_data(t_data *data, char *errmsg, int errnum);
#endif