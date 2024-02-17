/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:58:29 by hp                #+#    #+#             */
/*   Updated: 2024/02/13 20:59:05 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

void	sigint_handler_heredoc(int signum)
{
	(void)signum;
	g_exit = 1;
	ioctl(STDOUT_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}
