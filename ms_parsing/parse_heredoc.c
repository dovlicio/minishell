/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:26:53 by hp                #+#    #+#             */
/*   Updated: 2024/02/22 18:33:40 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_heredoc_expander(t_minishell *shell, char *input, char *delim, int fd)
{
	char	*input3;
	int		i;

	i = 0;
	input3 = ft_strdup("");
	while (input[i])
	{
		if (input[i] == '$' && !ft_quote_exists(delim))
		{
			input3 = ft_checker(input3, ft_substr(input, 0, i));
			input3 = ft_checker(input3, ft_handle_dolar(shell, input, &i, 1));
			if (!input3)
				return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
			input = &input[i];
			i = 0;
		}
		else if (!input[++i])
		{
			input3 = ft_checker(input3, ft_substr(input, 0, i));
			if (!input3)
				return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
		}
	}
	return (ft_putstr_fd(input3, fd), \
			ft_putchar_fd('\n', fd), free(input3), 0);
}

char	*ft_readline_init(t_minishell *shell, char *delimiter, int fd)
{
	char	*input;

	input = readline("> ");
	if (g_exit)
	{
		shell->sig_heredoc = 1;
		return (free(delimiter), close(fd), \
				ft_print_error(shell, NULL, NULL, 130), NULL);
	}
	if (!input)
	{
		input = ft_strdup(delimiter);
		return (ft_print_error(shell, ERROR_HEREDOC_EOF_DELIM, \
				NULL, 131), input);
	}
	return (input);
}

int	ft_read_input(t_minishell *shell, char *delim, int fd)
{
	char	*input;
	char	*start;
	char	*delimiter;

	delimiter = ft_remove_quotes(delim);
	if (!delimiter)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	signal(SIGINT, sigint_handler_heredoc);
	while (1)
	{
		input = ft_readline_init(shell, delimiter, fd);
		if (!input)
			return (-1);
		if (ft_strncmp(input, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(input);
			break ;
		}
		start = input;
		if (ft_heredoc_expander(shell, input, delim, fd) == -1)
			return (free(start), free(delimiter), close(fd), -1);
		free(start);
	}
	(free(delimiter), close(fd));
	return (0);
}

static int	ft_heredoc_init(t_minishell *shell, char *copy, \
							char **copy2, int *i)
{
	if (shell->fd_stdin != 0)
		close(shell->fd_stdin);
	shell->fd_stdin = shell->current_heredoc->fd;
	shell->current_heredoc = shell->current_heredoc->next;
	*copy2 = ft_strdup(shell->cmd_args[*i + 1]);
	if (!(*copy2))
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	shell->cmd_args = ft_delete_arg(shell, copy);
	if (!shell->cmd_args)
		return (free(*copy2), -1);
	return (0);
}

int	ft_parse_heredoc(t_minishell *shell, char *str)
{
	char	*copy;
	char	*copy2;
	int		i;

	copy2 = NULL;
	copy = ft_strdup(str);
	if (!copy)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	i = 0;
	while (shell->cmd_args[i])
	{
		if (ft_strncmp(shell->cmd_args[i], copy, ft_strlen(copy) + 1) == 0)
		{
			if (ft_heredoc_init(shell, copy, &copy2, &i) == -1)
				return (free(copy), -1);
			shell->cmd_args = ft_delete_arg(shell, copy2);
			if (!shell->cmd_args)
				return (free(copy), free(copy2), -1);
			(free(copy), free(copy2));
			shell->in_redirect = 1;
			return (0);
		}
		i++;
	}
	return (0);
}
