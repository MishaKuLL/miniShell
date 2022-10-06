/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin		g_builtin[] = 
{
	{"echo", &cmd_echo},
	{"cd", &cmd_cd},
	{"exit", &cmd_exit},
	{"pwd", &cmd_pwd},
	{"unset", &cmd_unset},
	{"env", &cmd_env},
	{"export", &cmd_export},
};

void	launch(t_command *cmds)
{
	t_command	*tmp;
	int			i;

	i = 0;
	tmp = cmds;
	while (tmp)
	{
		if (tmp->args[0])
		{
			if (tmp->pipe_flag)
				execute_pipe(&tmp);
			else if (tmp->redir_flag)
				execute_redirects(tmp->args, tmp);
			else
				execute(tmp->args);
		}
		tmp = tmp->next;
	}
}

char	*join_path(char *path, char *arg)
{
	char		*new;
	char		*tmp;
	struct stat	stats;

	new = ft_strjoin(path, "/");
	tmp = new;
	new = ft_strjoin(new, arg);
	free(tmp);
	if ((stat(new, &stats) == 0))
		return (new);
	free(new);
	return (NULL);
}

void	find_cmd(char **args)
{
	char		**path;
	int			i;
	char		*tmp;
	char		*new;

	i = 0;
	while (g_env[i] && !(ft_strnstr(g_env[i], "PATH=", 5)))
		i++;
	if (!g_env[i])
		return ;
	path = ft_strtok(g_env[i] + 5, ":");
	if (!path)
		error(ER_MALLOC);
	i = -1;
	while (path[++i])
	{
		new = join_path(path[i], args[0]);
		if (new)
		{
			tmp = args[0];
			args[0] = new;
			free_arr(path);
			free(tmp);
			execute_process(args);
			return ;
		}
	}
	free_arr(path);
	error_no_cmd(args[0]);
}

void	execute(char **args)
{
	int			i;
	struct stat	stats;

	i = 0;
	if (args[0] && args[0][0] == '\0')
		return (error_no_cmd(args[0]));
	while (i < 7)
	{
		if (!(ft_strncmp(args[0], g_builtin[i].name, \
			ft_strlen(g_builtin[i].name))))
		{
			g_builtin[i].func(args);
			return ;
		}
		i++;
	}
	if ((stat(args[0], &stats) == 0) && \
		(S_ISREG(stats.st_mode)) && (stats.st_mode & S_IXUSR))
		execute_process(args);
	else
		find_cmd(args);
}

void	execute_process(char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		error(ER_FORK);
	if (pid == 0)
	{
		if (execve(args[0], args, g_env) == -1)
		{
			error(ER_EXECUTE);
			exit(WTERMSIG(status));
		}
	}
	else
	{
		ignore_signals();
		waitpid(pid, &status, WUNTRACED);
		if (WIFSIGNALED(status))
			handle_child_signals(status);
		else
			g_exit = WEXITSTATUS(status);
		handle_signals();
	}
}
