/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:11:07 by hp                #+#    #+#             */
/*   Updated: 2024/02/23 15:08:41 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_del_in_red(t_minishell *shell, char *copy, int *i)
{
	char	*copy2;

	copy2 = ft_strdup(shell->cmd_args[*i + 1]);
	if (!copy2)
		return (free(copy), \
				ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	shell->cmd_args = ft_delete_arg(shell, copy);
	if (!shell->cmd_args)
		return (free(copy), free(copy2), -1);
	shell->cmd_args = ft_delete_arg(shell, copy2);
	if (!shell->cmd_args)
		return (free(copy), free(copy2), -1);
	(free(copy), free(copy2));
	shell->in_redirect = 1;
	return (0);
}

static int	ft_check_error(t_minishell *shell, char *copy, int *i)
{
	if (ft_is_piped(shell) && access(shell->cmd_args[*i + 1], F_OK) == 0 && \
		access(shell->cmd_args[*i + 1], R_OK) != 0)
		return (free(copy), ft_set_error(shell, ERROR_PERMISSION_DENIED), 3);
	if (ft_is_piped(shell))
		return (free(copy), ft_set_error(shell, ERROR_NO_SUCH_FILE), 3);
	if (access(shell->cmd_args[*i + 1], F_OK) == 0 && \
		access(shell->cmd_args[*i + 1], R_OK) != 0)
		return (free(copy), ft_print_error(shell, ERROR_PERMISSION_DENIED, \
				shell->cmd_args[*i + 1], 1), -1);
	return (free(copy), ft_print_error(shell, ERROR_NO_SUCH_FILE, \
			shell->cmd_args[*i + 1], 1), -1);
}

static int	ft_setup_stdin(t_minishell *shell, int *i, char *copy)
{
	if (shell->fd_stdin > 0)
		close(shell->fd_stdin);
	(void)copy;
	if (ft_remove_empty(shell, shell->cmd_args[*i + 1]) == -1)
		return (free(copy), -1);
	if (ft_expand(shell, shell->cmd_args[*i + 1], *i + 1) == -1)
		return (free(copy), -1);
	shell->fd_stdin = open(shell->cmd_args[*i + 1], O_RDONLY);
	return (0);
}

int	ft_parse_input(t_minishell *shell, char *str)
{
	char	*copy;
	int		i;

	copy = ft_strdup(str);
	if (!copy)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	i = 0;
	while (shell->cmd_args[i])
	{
		if (ft_strncmp(shell->cmd_args[i], copy, ft_strlen(copy) + 1) == 0)
		{
			if (ft_setup_stdin(shell, &i, copy) == -1)
				return (-1);
			if (shell->fd_stdin == -1)
				return (ft_check_error(shell, copy, &i));
			if (ft_del_in_red(shell, copy, &i) == -1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (0);
}
