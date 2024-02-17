/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:14:27 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/12 13:59:04 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_pwd(t_minishell *shell, int *fd)
{
	char	*pwd;
	int		tmp_fd;

	if (shell->piped && !shell->out_redirect)
		tmp_fd = fd[1];
	else
		tmp_fd = shell->fd_stdout;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	ft_putstr_fd(pwd, tmp_fd);
	ft_putstr_fd("\n", tmp_fd);
	free(pwd);
	return (0);
}
