/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:17:38 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/13 20:59:01 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static void	sigint_handler(int signum)
{
	(void)signum;
	g_exit = 1;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	signint_child_handler(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", 1);
}

static void	sigquit_handler(int signum)
{
	(void)signum;
	ft_putstr_fd("Quit (core dumped)\n", 2);
}

void	ft_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_child_signals(void)
{
	signal(SIGINT, signint_child_handler);
	signal(SIGQUIT, sigquit_handler);
}
