/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:13:51 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/13 21:42:37 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_change_env_value(t_minishell *shell, char *env)
{
	int	i;

	i = 0;
	while (shell->envp[i] && (ft_strncmp(shell->envp[i], \
			env, ft_get_n(shell->envp[i], env)) != 0))
		i++;
	free(shell->envp[i]);
	shell->envp[i] = ft_strdup(env);
	if (!shell->envp[i])
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	return (1);
}

static int	ft_search_key(t_minishell *shell, char *env)
{
	int	i;
	int	n;
	int	empty;

	n = 0;
	empty = 0;
	while (env[n] && env[n] != '=')
		n++;
	if (!env[n])
		empty = 1;
	i = 0;
	while (shell->envp[i])
	{
		if (!ft_strncmp(shell->envp[i], env, \
			ft_get_n(shell->envp[i], env)) && !empty)
			return (0);
		else if (!ft_strncmp(shell->envp[i], env, \
				ft_get_n(shell->envp[i], env)) && empty)
			return (2);
		i++;
	}
	return (1);
}

static void	ft_print_exported(t_minishell *shell, int *fd)
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
		if (!ft_strncmp(shell->envp[i], "_=", 2))
		{
			i++;
			continue ;
		}
		ft_export_printer(shell, &i, tmp_fd);
		i++;
	}
}

static int	ft_export_helper(t_minishell *shell, int *i)
{
	if (!ft_search_key(shell, shell->cmd_args[*i]))
	{
		if (!ft_change_env_value(shell, shell->cmd_args[*i]))
			return (-1);
	}
	else if (ft_search_key(shell, shell->cmd_args[*i]) == 2)
	{
		(*i)++;
		return (1);
	}
	else if (ft_search_key(shell, shell->cmd_args[*i]) == 1)
	{
		shell->envp = ft_import_env(shell, shell->cmd_args[*i]);
		if (!shell->envp)
			return (-1);
	}
	return (0);
}

int	ft_export(t_minishell *shell, int *fd)
{
	int		i;
	int		status;

	if (!shell->cmd_args[1])
		ft_print_exported(shell, fd);
	else
	{
		if (ft_is_piped(shell))
			return (0);
		i = 1;
		if (ft_check_key(shell->cmd_args[i]) == -1)
			return (ft_print_error(shell, ERROR_NOT_VALID_IDENT, NULL, 1), \
					ft_set_exit(shell, -1));
		while (shell->cmd_args[i])
		{
			status = ft_export_helper(shell, &i);
			if (status == -1)
				return (-1);
			if (status == 1)
				continue ;
			i++;
		}
	}
	return (0);
}
