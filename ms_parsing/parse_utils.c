/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:19:25 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/15 20:22:51 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

char	*ft_remove_quotes(char *delim)
{
	char	*delimiter;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (delim[i])
	{
		if (delim[i] != '"' && delim[i] != '\'')
			j++;
		i++;
	}
	delimiter = ft_calloc(j + 1, sizeof(char *));
	if (!delimiter)
		return (NULL);
	i = 0;
	j = 0;
	while (delim[i])
	{
		if (delim[i] != '"' && delim[i] != '\'')
			delimiter[j++] = delim[i];
		i++;
	}
	delimiter[j] = '\0';
	return (delimiter);
}

void	ft_set_error(t_minishell *shell, char *str)
{
	shell->err_msg = str;
	shell->exit_status = 1;
}

static int	ft_copy_and_del(char **new_cmds, t_minishell *shell, char *str)
{
	int	i;
	int	j;
	int	freed;

	j = 0;
	i = 0;
	freed = 0;
	while (shell->cmd_args[j])
	{
		if (!freed && ft_strncmp(shell->cmd_args[j], str, ft_strlen(str)) == 0)
		{
			freed = 1;
			free(shell->cmd_args[j++]);
		}
		else
		{
			new_cmds[i++] = ft_strdup(shell->cmd_args[j]);
			if (!new_cmds[i - 1])
				return (free_matrix(new_cmds), \
						ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
			free(shell->cmd_args[j++]);
		}
	}
	return (1);
}

char	**ft_delete_arg(t_minishell *shell, char *str)
{
	char	**new_cmds;
	int		j;

	j = 0;
	while (shell->cmd_args[j])
		j++;
	new_cmds = ft_calloc(j, sizeof(char *));
	if (!new_cmds)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), NULL);
	new_cmds[j - 1] = 0;
	if (ft_copy_and_del(new_cmds, shell, str) == -1)
		return (NULL);
	return (free(shell->cmd_args), new_cmds);
}

void	ft_if_cleared_put_logo(t_minishell *shell, char *path)
{
	if (!ft_strncmp(path, "/usr/bin/clear", 20) && !shell->piped)
		shell->logo = 1;
	else if (!ft_strncmp(path, "clear", 10) && !shell->piped)
		shell->logo = 1;
}
