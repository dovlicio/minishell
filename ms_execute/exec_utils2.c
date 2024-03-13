/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:39:21 by hp                #+#    #+#             */
/*   Updated: 2024/02/21 17:18:06 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

void	ft_close_redirections(t_minishell *shell)
{
	if (shell->in_redirect && shell->fd_stdin != 0)
	{
		close(shell->fd_stdin);
		shell->fd_stdin = 0;
	}
	if (shell->out_redirect && shell->fd_stdout != 1)
	{
		close(shell->fd_stdout);
		shell->fd_stdout = 1;
	}
}

void	ft_child_exit(t_minishell *shell, int *status)
{
	if (WIFEXITED(*status))
		shell->exit_status = WEXITSTATUS(*status);
	if (WIFSIGNALED(*status))
		shell->exit_status = WTERMSIG(*status) + 128;
}

char	**ft_import_env(t_minishell *shell, char *env)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (shell->envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), NULL);
	i = 0;
	if (!ft_copy_env(shell, new_envp, &i))
		return (NULL);
	new_envp[i++] = ft_strdup(env);
	if (!new_envp[i - 1])
	{
		free_matrix(new_envp);
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), NULL);
	}
	new_envp[i] = NULL;
	free(shell->envp);
	return (new_envp);
}

int	ft_is_piped(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->type == T_PIPE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_count_pipes(t_minishell *shell)
{
	int		count;
	t_token	*tmp;

	count = 1;
	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->type == T_PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
