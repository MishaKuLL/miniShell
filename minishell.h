/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:26:55 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils/utils.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# define PROMPT "\n\033[1;31m$minishell$~> \033[0m"
# define ER_FORK 0
# define ER_EXECUTE 1
# define ER_MALLOC 2
# define ER_FILE 3
# define ER_SYNTAX 4

typedef struct s_builtin
{
	char				*name;
	void				(*func)(char **args);
}						t_builtin;

typedef struct s_command
{
	char				**args;
	int					args_size;
	int					pipe_flag;
	int					redir_flag;
	char				*in_fname;
	char				*out_fname;
	int					append;
	struct s_command	*next;
}						t_command;

int						g_exit;
char					**g_env;

void					cmd_echo(char **args);
void					cmd_cd(char **args);
void					cmd_exit(char **args);
void					cmd_env(char **args);
void					cmd_export(char **args);
void					cmd_pwd(char **args);
void					cmd_unset(char **args);

char					**read_envp(char **envp);
void					shell_loop(void);

void					launch(t_command *cmds);
void					execute(char **args);
void					execute_process(char **args);
void					find_cmd(char **args);

void					error(int error);
void					error_errno(void);
void					error_no_cmd(char *arg);
void					error_exit(char *arg);
void					error_cd(char *arg);

int						parsing(char *line, t_command *cmds);
int						what_to_parse(char **line, t_command *cmd);
int						parse_next_command(char line_char, t_command **cmds);
int						parse_command(t_command *cmd, char *line);
int						skip_spaces(char *line);

int						parsing_env(char *line, t_command *cmd);
int						env_symb_skip(char *env_str, char *line, int i);
int						env_preparse(char *line, char **arg);

int						parsing_redirects(char redir_symb, char *line, \
						t_command *cmds);

int						parsing_quotes(char *line, char quote, t_command *cmd);

void					handle_signals(void);
void					sigint(int sig);
void					sigquit(int sig);
void					handle_child_signals(int status);
void					ignore_signals(void);

t_command				*new_cmd_list(void);
void					free_cmd_list(t_command **cmds);

void					execute_pipe(t_command **cmds);
void					fork_pipe(int save_fd, int *fd, t_command *cmds);
void					child_pipe(int *fd, int save_fd, t_command *cmds);

void					execute_redirects(char **args, t_command *cmd);

#endif
