/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:07:03 by hp                #+#    #+#             */
/*   Updated: 2024/02/17 15:12:11 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_path_helper(t_minishell *shell, char *s2, char **path, int *i)
{
	int	j;

	j = 0;
	if (!shell->cmd_args[0][j])
		return (1);
	while (shell->cmd_args[0][j] && shell->cmd_args[0][j] == '/')
		j++;
	if (!shell->cmd_args[0][j])
		return (ft_print_error(shell, ERROR_IS_DIR, \
				shell->cmd_args[0], 126), 2);
	if (ft_get_full_path(shell, s2, path, i) == -1)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	if (access(*path, F_OK) == 0 && access(*path, X_OK) == 0 && \
		!ft_is_abs_or_rel(shell->cmd_args[0]))
		return (0);
	else if (access(*path, F_OK) == 0 && access(*path, X_OK) != 0)
		return (ft_print_error(shell, ERROR_PERMISSION_DENIED, \
				shell->cmd_args[0], 126), 1);
	(free(*path), (*i)++);
	return (10);
}

static int	ft_path_check(t_minishell *shell, char *s2, char **path)
{
	int	i;
	int	status;

	i = 0;
	while (shell->paths[i])
	{
		status = ft_path_helper(shell, s2, path, &i);
		if (status == 1)
			break ;
		else if (status != 10)
			return (status);
	}
	*path = ft_strdup(shell->cmd_args[0]);
	if (!*(path))
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, *path, 1), -1);
	if (access(*path, F_OK) == 0 && access(*path, X_OK) != 0)
		return (ft_print_error(shell, ERROR_PERMISSION_DENIED, *path, 126), -9);
	if (!shell->cmd_args[0][0] || (access(*path, F_OK) == 0 && \
		access(*path, X_OK) == 0 && !ft_is_dir(path)) || \
		!ft_is_abs_or_rel(*path))
		return (0);
	if (ft_is_dir(path) == 2)
		return (ft_print_error(shell, \
				ERROR_IS_DIR, shell->cmd_args[0], 126), -11);
	return (ft_print_error(shell, ERROR_NO_SUCH_FILE, *path, 127), -12);
}

int	ft_get_path(t_minishell *shell, char **path)
{
	char	*s2;
	int		status;

	s2 = NULL;
	*path = ft_extract_env_value(shell->envp, "PATH");
	if (!(*path))
	{
		*path = ft_strdup(shell->cmd_args[0]);
		if (!*path)
			return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
		if (ft_is_abs_or_rel(*path) && access(*path, F_OK) == 0)
			return (ft_print_error(shell, ERROR_IS_DIR, *path, 126), \
					free(*path), 2);
		return (0);
	}
	shell->paths = ft_split(*path, ':');
	if (!shell->paths)
		return (-1);
	status = ft_path_check(shell, s2, path);
	if (status != 0 && status != 2 && status != -1)
		free(*path);
	return (status);
}
