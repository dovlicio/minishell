/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:13:08 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/13 21:06:06 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static void	ft_check_option(t_minishell *shell, int	*i, int *n)
{
	int	j;

	while (shell->cmd_args[*i] && !ft_strncmp(shell->cmd_args[*i], "-n", 2))
	{
		j = 2;
		while (shell->cmd_args[*i][j])
		{
			if (shell->cmd_args[*i][j] && shell->cmd_args[*i][j] == 'n')
				j++;
			else
				break ;
		}
		if (shell->cmd_args[*i][j])
			break ;
		(*i)++;
		*n = 1;
	}
}

int	ft_echo(t_minishell *shell, int *fd)
{
	int	i;
	int	n;
	int	tmp_fd;

	i = 1;
	n = 0;
	if (shell->piped && !shell->out_redirect)
		tmp_fd = fd[1];
	else
		tmp_fd = shell->fd_stdout;
	ft_check_option(shell, &i, &n);
	while (shell->cmd_args[i])
	{
		ft_putstr_fd(shell->cmd_args[i], tmp_fd);
		if (shell->cmd_args[i + 1])
			ft_putstr_fd(" ", tmp_fd);
		i++;
	}
	if (!n)
		ft_putstr_fd("\n", tmp_fd);
	return (0);
}
