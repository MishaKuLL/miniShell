/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:40:02 by asherlin          #+#    #+#             */
/*   Updated: 2022/08/30 22:32:27 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "libft.h"
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>

# define D_QUOTE '\"'
# define QUOTE '\''

int	g_ret_number;

typedef struct s_struct
{
	bool	has_flag;
	int		num_tokens;
	char	quote;
	char	*line;
	char	*line_read;
	char	*name_file;
	char	*error_name_file;
	char	*home;
	char	**tokens;
	char	*cmd;
	int		last_redir;
	int		is_append;
	int		out_fd;
	int		in_fd;
	int		c;

}	t_struct;

/*
** tokenizer.c
*/
typedef struct s_token
{
	char	*to_print;
	char	*to_exec;
	char	quote;
	char	*end;
	char	*new;
	int		i;
	int		init;
	int		len;
	int		posic;
}			t_token;

void	initialize(t_struct *data);
void	print_prompt2(void);
void	print_prompt1(void);
void	free_data(t_struct *data, char *errmsg, int errnum);
char	*read_cmd(char *buf);

#endif
