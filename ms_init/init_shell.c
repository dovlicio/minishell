/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:17:06 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 18:59:11 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

void	ft_clear(char **envp)
{
	int		child_pid;
	char	*clear_args[2];

	clear_args[0] = "/usr/bin/clear";
	clear_args[1] = NULL;
	child_pid = fork();
	if (!child_pid)
	{
		if (execve("/usr/bin/clear", clear_args, envp) == -1)
			(ft_putstr_fd("minishell: clear: failed to execute\n", 1), exit(1));
	}
	wait(NULL);
	(void)envp;
}

void	ft_init_shell(t_minishell *shell, int argc, char **argv, char **envp)
{
	if (argc != 1 && argv[0])
		(ft_print_error(shell, ERROR_INVALID_ARGUMENT, NULL, 1), exit(1));
	ft_memset(shell, 0, sizeof(t_minishell));
	shell->envp = ft_extract_envp(envp);
	if (!shell->envp)
		ft_clean_all(shell, 1, ERROR_ENV_IMPORT_FAILED);
	ft_clear(envp);
	ft_init_logo();
	shell->exit_status = 0;
	shell->fd_stdin = 0;
	shell->fd_stdout = 1;
	shell->heredoc = 0;
	shell->in_redirect = 0;
	shell->out_redirect = 0;
	shell->logo = 0;
	g_exit = 0;
}

void	ft_init_prompt(t_minishell *shell)
{
	shell->user_input = \
		readline("\001\e\x1b[36m\002minishell\001\e\x1b[0m\002: ");
	if (!shell->user_input)
	{
		if (g_exit == 1)
			shell->exit_status = 130;
		(ft_putstr_fd("exit\n", 1), \
		ft_clean_all(shell, shell->exit_status, NULL));
	}
	if (shell->user_input[0])
		add_history(shell->user_input);
}

char	**ft_extract_envp(char **envp)
{
	char	**env_copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	env_copy = ft_calloc((i + 1), sizeof(char *));
	if (!env_copy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		env_copy[i] = ft_strdup(envp[i]);
		if (!env_copy[i])
			return (free_matrix(env_copy), NULL);
		i++;
	}
	env_copy[i] = 0;
	return (env_copy);
}
