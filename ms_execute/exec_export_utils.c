/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:25:44 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/13 21:28:03 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_strlen_env(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

void	ft_export_printer(t_minishell *shell, int *i, int tmp_fd)
{
	int	j;

	j = 0;
	ft_putstr_fd("declare -x ", tmp_fd);
	while (shell->envp[*i][j] && shell->envp[*i][j] != '=')
		ft_putchar_fd(shell->envp[*i][j++], tmp_fd);
	if (shell->envp[*i][j] == '=')
		ft_putchar_fd(shell->envp[*i][j++], tmp_fd);
	if (shell->envp[*i][j])
		ft_putstr_fd_new(tmp_fd, &shell->envp[*i][j]);
	if (shell->envp[*i][j - 1] == '=' && !shell->envp[*i][j])
		ft_putstr_fd("\"\"\n", tmp_fd);
	if (shell->envp[*i][j - 1] != '=' && !shell->envp[*i][j])
		ft_putchar_fd('\n', tmp_fd);
}

int	ft_get_n(char *env, char *arg)
{
	int	n1;
	int	n2;

	n1 = ft_strlen_env(env);
	n2 = ft_strlen_env(arg);
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int	ft_copy_env(t_minishell *shell, char **new, int *i)
{
	while (shell->envp[*i])
	{
		new[*i] = ft_strdup(shell->envp[*i]);
		if (!new[*i])
			return (free_matrix(new), \
					ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
		free(shell->envp[*i]);
		(*i)++;
	}
	return (1);
}

int	ft_check_key(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[i] != '_')
		return (-1);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (-1);
		i++;
	}
	return (0);
}
