/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 18:42:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_child_signals(int status)
{
	if (WTERMSIG(status) == 2)
		g_exit = 130;
	if (WTERMSIG(status) == 3)
	{
		ft_putstr_fd("Quit: 3", 1);
		g_exit = 131;
	}
	ft_putchar_fd('\n', 1);
}

void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_signals(void)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
}

void	sigint(int sig)
{
	write(0, "\b\b  \b\b", 6);
	write(0, "\n", 1);
	ft_putstr_fd(PROMPT, 1);
	g_exit = 1;
}

void	sigquit(int sig)
{
	write(0, "\b\b  \b\b", 6);
	g_exit = 0;
}
