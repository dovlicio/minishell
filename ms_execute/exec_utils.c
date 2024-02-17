/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:15:24 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/14 01:42:01 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

void	ft_putstr_fd_new(int fd, char *str)
{
	ft_putchar_fd('"', fd);
	ft_putstr_fd(str, fd);
	ft_putchar_fd('"', fd);
	ft_putstr_fd("\n", fd);
}

char	*ft_extract_env_value(char **envp, char *var)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], var, ft_strlen(var)) && \
			envp[i][ft_strlen(var)] == '=')
			return (&envp[i][ft_strlen(var) + 1]);
		i++;
	}
	return (NULL);
}

int	ft_is_dir(char **path)
{
	struct stat	path_stat;

	if (*path == NULL || **path == '\0')
		return (0);
	if ((*path)[0] == '~' && !(*path)[1])
		return (2);
	if ((*path)[0] != '.' && (*path)[0] != '/')
		*path = ft_checker(ft_strdup("./"), *path);
	if (stat(*path, &path_stat) == 0)
	{
		if (S_ISDIR(path_stat.st_mode))
			return (2);
	}
	return (0);
}

int	ft_is_abs_or_rel(char *path)
{
	int	i;
	int	slash;

	i = 0;
	slash = 0;
	if (path[i] == '~' && (!path[i + 1] || path[i + 1] == '/'))
	{
		i++;
		slash++;
	}
	while (path[i] && (path[i] == '.' || path[i] == '/'))
	{
		if (path[i] == '/')
		{
			slash++;
			break ;
		}
		i++;
	}
	if (slash > 0)
		return (1);
	return (0);
}

int	ft_get_full_path(t_minishell *shell, char *s2, char **path, int *i)
{
	s2 = ft_strjoin("/", shell->cmd_args[0]);
	if (!s2)
		return (-1);
	*path = ft_strjoin(shell->paths[*i], s2);
	if (!(*path))
		return (free(s2), -1);
	free(s2);
	return (0);
}
