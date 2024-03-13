/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:10:23 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 15:52:26 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_set_exit(t_minishell *shell, int status)
{
	if (status < 0)
		shell->exit_status = 1;
	else
		shell->exit_status = status;
	return (status);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}

void	ft_clean_all(t_minishell *shell, int exit_status, char *error)
{
	free_matrix(shell->envp);
	free_matrix(shell->cmd_args);
	free_matrix(shell->paths);
	if (shell->user_input)
		free(shell->user_input);
	ft_clean_tokens(&(shell->tokens));
	rl_clear_history();
	if (error)
		ft_putstr_fd(error, 2);
	shell->exit_status = exit_status;
	if (shell->fd_stdin != 0)
		close(shell->fd_stdin);
	if (shell->fd_stdout != 1)
		close(shell->fd_stdout);
	exit(exit_status);
}

static void	ft_close_stds(t_minishell *shell)
{
	if (shell->fd_stdin > 0)
		close(shell->fd_stdin);
	if (shell->fd_stdout > 1)
		close(shell->fd_stdout);
}

void	ft_clean(t_minishell *shell)
{
	free_matrix(shell->paths);
	shell->paths = NULL;
	ft_clean_heredocs(&shell->heredoc_list);
	if (shell->sig_heredoc == 1)
	{
		shell->exit_status = 130;
		g_exit = 0;
	}
	shell->sig_heredoc = 0;
	if (shell->cmd_args && shell->cmd_args[0])
		g_exit = 0;
	free_matrix(shell->cmd_args);
	shell->cmd_args = NULL;
	free(shell->user_input);
	shell->user_input = NULL;
	ft_clean_tokens(&(shell->tokens));
	ft_close_stds(shell);
	shell->fd_stdin = 0;
	shell->fd_stdout = 1;
	if (shell->logo)
	{
		ft_init_logo();
		shell->logo = 0;
	}
}
