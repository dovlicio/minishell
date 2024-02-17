/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:13:33 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/12 12:53:22 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_env(t_minishell *shell, int *fd)
{
	int	i;
	int	tmp_fd;

	if (shell->piped && !shell->out_redirect)
		tmp_fd = fd[1];
	else
		tmp_fd = shell->fd_stdout;
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strchr(shell->envp[i], '='))
		{
			ft_putstr_fd(shell->envp[i], tmp_fd);
			ft_putstr_fd("\n", tmp_fd);
		}
		i++;
	}
	return (0);
}
