/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:11:47 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/14 01:58:48 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_is_builtin(t_minishell *shell, int *fd)
{
	int	status;

	status = 1;
	if (!ft_strncmp(shell->cmd_args[0], "cd", 3))
		status = ft_cd(shell);
	else if (!ft_strncmp(shell->cmd_args[0], "env", 4))
		status = ft_env(shell, fd);
	else if (!ft_strncmp(shell->cmd_args[0], "export", 7))
		status = ft_export(shell, fd);
	else if (!ft_strncmp(shell->cmd_args[0], "unset", 6))
		status = ft_unset(shell);
	else if (!ft_strncmp(shell->cmd_args[0], "echo", 5))
		status = ft_echo(shell, fd);
	else if (!ft_strncmp(shell->cmd_args[0], "pwd", 4))
		status = ft_pwd(shell, fd);
	else if (!ft_strncmp(shell->cmd_args[0], "exit", 5))
		status = ft_exit(shell);
	if (status == 0)
		shell->exit_status = 0;
	return (status);
}
