/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:20:10 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 15:50:28 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static void	ft_get_next_token(t_minishell *shell, int *args_count)
{
	while (shell->current_token && shell->current_token->type != T_PIPE)
	{
		(*args_count)++;
		shell->current_token = shell->current_token->next;
	}
}

int	ft_init_cmd_args(t_minishell *shell)
{
	int		args_count;
	int		i;
	t_token	*tmp;

	if (shell->current_token && shell->current_token->type == T_PIPE)
		shell->current_token = shell->current_token->next;
	tmp = shell->current_token;
	args_count = 0;
	ft_get_next_token(shell, &args_count);
	shell->cmd_args = ft_calloc(args_count + 1, sizeof(char *));
	if (!shell->cmd_args)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	shell->cmd_args[args_count] = 0;
	i = 0;
	while (tmp && tmp->type != T_PIPE)
	{
		shell->cmd_args[i] = ft_strdup(tmp->value);
		if (!shell->cmd_args[i])
			return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	ft_parse_redirections(t_minishell *shell)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (shell->cmd_args[i])
	{
		if (ft_strncmp(shell->cmd_args[i], "<<", 3) == 0)
			status = ft_parse_heredoc(shell, shell->cmd_args[i]);
		else if (ft_strncmp(shell->cmd_args[i], "<", 2) == 0)
			status = ft_parse_input(shell, shell->cmd_args[i]);
		else if (ft_strncmp(shell->cmd_args[i], ">>", 3) == 0)
			status = ft_parse_output(shell, shell->cmd_args[i], 3);
		else if (ft_strncmp(shell->cmd_args[i], ">", 2) == 0)
			status = ft_parse_output(shell, shell->cmd_args[i], 2);
		else
			i++;
		ft_signals();
		if (status == -1)
			return (-1);
		if (status == 3)
			return (0);
	}
	return (0);
}

int	ft_parse(t_minishell *shell)
{
	if (ft_check_syntax_errors(shell) == -1)
		return (-1);
	if (ft_init_heredocs(shell) == -1)
		return (-1);
	if (ft_init_cmd_args(shell) == -1)
		return (-1);
	if (!shell->cmd_args[0])
		return (-1);
	if (ft_parse_redirections(shell) == -1)
		return (-1);
	if (ft_expand_vars(shell) == -1)
		return (-1);
	return (0);
}
