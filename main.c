/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:26:49 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**g_env;
	int		g_exit;

	g_env = read_envp(envp);
	g_exit = 0;
	handle_signals();
	shell_loop();
	return (0);
}

char	**read_envp(char **envp)
{
	char	**env_data;
	int		i;
	int		j;

	i = 0;
	while (envp[i])
		i++;
	env_data = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env_data)
		error(ER_MALLOC);
	i = 0;
	while (envp[i])
	{
		env_data[i] = ft_strdup(envp[i]);
		if (!env_data[i])
			error(ER_MALLOC);
		i++;
	}
	env_data[i] = NULL;
	return (env_data);
}

void	shell_loop(void)
{
	char		*line;
	t_command	*cmds;

	line = NULL;
	while (1)
	{
		cmds = new_cmd_list();
		ft_putstr_fd(PROMPT, 1);
		get_next_line(&line);
		if (parsing(line, cmds))
			launch(cmds);
		free_cmd_list(&cmds);
		free(line);
		line = NULL;
	}
}
