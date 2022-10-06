/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(char **args)
{
	int	i;
	int	j;

	ft_putendl_fd("exit", 1);
	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		exit(EXIT_SUCCESS);
	j = 0;
	if (args[1][j] == '-' || args[1][j] == '+')
		j++;
	while (args[1][j])
	{
		if (!ft_isdigit(args[1][j]))
			error_exit(args[1]);
		j++;
	}
	if (i == 2)
		exit(ft_atoi(args[1]) % 256);
	else
		ft_putendl_fd("shell: exit: too many arguments", STDERR_FILENO);
}
