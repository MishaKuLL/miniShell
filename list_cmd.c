/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*new_cmd_list(void)
{
	t_command	*cmds;

	cmds = NULL;
	cmds = (t_command *)malloc(sizeof(t_command));
	if (!cmds)
		error(ER_MALLOC);
	cmds->args = (char **)malloc(sizeof(char *) * 2);
	if (!cmds->args)
		error(ER_MALLOC);
	else
	{
			cmds->args[0] = NULL;
			cmds->args[1] = NULL;
	}
	cmds->args_size = 1;
	cmds->pipe_flag = 0;
	cmds->redir_flag = 0;
	cmds->in_fname = NULL;
	cmds->out_fname = NULL;
	cmds->append = 0;
	cmds->next = NULL;
	return (cmds);
}

void	free_cmd_list(t_command **cmds)
{
	t_command	*next;

	while (*cmds)
	{
		next = (*cmds)->next;
		if ((*cmds)->args)
			free_arr((*cmds)->args);
		if ((*cmds)->in_fname)
			free((*cmds)->in_fname);
		if ((*cmds)->out_fname)
			free((*cmds)->out_fname);
		free(*cmds);
		*cmds = next;
	}
}
