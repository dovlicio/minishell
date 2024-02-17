/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:15:49 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/17 15:18:28 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static void	ft_exec_simple_cmd(t_minishell *shell, int *fd)
{
	int		child_pid;
	char	*path;
	int		status;

	path = shell->cmd_args[0];
	status = ft_is_builtin(shell, fd);
	if (status == 0 || status == -1 || ft_get_path(shell, &path) != 0)
		return ;
	(ft_set_exit(shell, 0), ft_child_signals());
	ft_if_cleared_put_logo(shell, path);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (shell->fd_stdout > 1 && dup2(shell->fd_stdout, 1) == -1)
			ft_clean_all(shell, 1, NULL);
		if (shell->fd_stdin > 0 && dup2(shell->fd_stdin, 0) == -1)
			ft_clean_all(shell, 1, NULL);
		ft_close_redirections(shell);
		if (shell->piped)
			close(fd[0]);
		if ((execve(path, &(shell->cmd_args[0]), shell->envp)) == -1)
			(ft_print_error(shell, ERROR_CMD_NOT_FOUND, shell->cmd_args[0], 1), \
							free(path), ft_clean_all(shell, 127, NULL));
	}
	waitpid(child_pid, &status, 0);
	ft_child_exit(shell, &status, &path);
}

static void	ft_exec_pipe(t_minishell *shell, int *fd)
{
	if (shell->current_token)
		shell->piped = 1;
	if (shell->piped && pipe(fd) == -1)
		return ;
	else if (!shell->out_redirect)
		shell->fd_stdout = 1;
	if (shell->piped && !shell->out_redirect)
		shell->fd_stdout = fd[1];
	if (!shell->err_msg && shell->cmd_args[0])
		ft_exec_simple_cmd(shell, fd);
	else if (shell->err_msg)
		ft_print_error(shell, shell->err_msg, NULL, 1);
	ft_close_redirections(shell);
	if (shell->piped)
	{
		close(fd[1]);
		shell->fd_stdout = 1;
	}
	shell->err_msg = NULL;
	shell->in_redirect = 0;
	shell->out_redirect = 0;
	shell->piped = 0;
}

static void	ft_exec_not_piped(t_minishell *shell)
{
	if (shell->cmd_args[0])
		ft_exec_simple_cmd(shell, NULL);
	ft_close_redirections(shell);
	shell->err_msg = NULL;
	shell->in_redirect = 0;
	shell->out_redirect = 0;
}

static int	ft_continue_exec(t_minishell *shell, int *fd)
{
	free_matrix(shell->cmd_args);
	free_matrix(shell->paths);
	shell->paths = NULL;
	shell->cmd_args = NULL;
	if (shell->fd_stdin != 0)
		close(shell->fd_stdin);
	shell->fd_stdin = fd[0];
	ft_init_cmd_args(shell);
	ft_parse_redirections(shell);
	if (!shell->cmd_args[0] && !shell->current_token)
		return (1);
	ft_expand_vars(shell);
	return (0);
}

void	ft_execute(t_minishell *shell)
{
	int	fd[2];
	int	i;

	if (!shell->tokens)
		return ;
	i = ft_count_pipes(shell);
	while (i--)
	{
		if (!ft_is_piped(shell))
			ft_exec_not_piped(shell);
		else
		{
			ft_exec_pipe(shell, fd);
			if (!i)
				break ;
			if (ft_continue_exec(shell, fd) == 1)
				return ;
		}
	}
}
