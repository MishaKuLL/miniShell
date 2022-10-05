/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

int		parsing_redirects(char redir_symb, char *line, t_command *cmds)
{
	int		j;
	char	*fname;
	int		fstart;

	fstart = 0;
	cmds->redir_flag = 1;
	cmds->append = ((line[fstart] == '>' && line[fstart++]) ? 1 : 0);
	while (line[fstart] == ' ')
		fstart++;
	if (ft_strchr("><", line[fstart]))
	{
		error(ER_SYNTAX);
		return (-1);
	}
	j = 0;
	while (line[fstart + j] && line[fstart + j] != ' ')
		j++;
	if (!(fname = (char*)malloc(sizeof(char) * (j + 1))))
		error(ER_MALLOC);
	ft_strlcpy(fname, line + fstart, j + 1);
	if (redir_symb == '>')
		cmds->out_fname = fname;
	else
		cmds->in_fname = fname;
	return (fstart + j + 1);
}
