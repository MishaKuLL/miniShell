/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	cmd_echo(char **args)
{
	int i;
	int n_flag;

	n_flag = 0;
	if (args[1])
	{
		i = 1;
		while (args[i] && !ft_strncmp(args[i], "-n", 2))
		{
			n_flag = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1);
}
