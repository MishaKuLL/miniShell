/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		parsing_quotes(char *line, char quote, t_command *cmd)
{
	int		i;
	int		j;
	int		n;

	j = 0;
	n = cmd->args_size - 1;
	i = 0;
	while (line[++i] && line[i] != quote)
	{
		if (line[i] == '$' && quote == '"')
			i += parsing_env(line + i + 1, cmd);
		else
		{
			if (line[i] == '\\' && quote == '"'
				&& ft_strchr("$\\\"", line[i + 1]))
				i++;
			if (cmd->args[n])
				j = ft_strlen(cmd->args[n]);
			if (!(cmd->args[n] = ft_realloc(cmd->args[n], j + 1)))
				error(ER_MALLOC);
			cmd->args[n][j] = line[i];
		}
	}
	(i == 1) ? (cmd->args[n] = ft_strdup("")) : 0;
	return (i);
}
