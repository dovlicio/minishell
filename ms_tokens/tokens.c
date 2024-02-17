/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:21:41 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/17 15:12:33 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_append_separator(t_token_type t_type, char **line,
	t_token **tokens)
{
	t_token	*token;

	token = ft_new_token(NULL, t_type);
	if (!token)
		return (ft_print_error(NULL, ERROR_MALLOC_FAIL, NULL, 1), 0);
	if (!ft_tokens_add_back(tokens, token))
		return (ft_print_error(NULL, ERROR_MALLOC_FAIL, NULL, 1), 0);
	(*line)++;
	if (t_type == T_DLESS || t_type == T_DGREATER)
		(*line)++;
	return (1);
}

static int	ft_append_identifier(char **line, t_token **tokens)
{
	char	*temp_line;
	char	*val;
	t_token	*token;
	size_t	i;

	i = 0;
	temp_line = *line;
	while (temp_line[i] && !ft_is_separator(temp_line[i]))
	{
		if (temp_line[i] == '\'' || temp_line[i] == '"')
		{
			if (!ft_skip_quotes(temp_line, &i))
				return (ft_print_error(NULL, ERROR_UNCLOSED_QUOTE, NULL, 1), 0);
		}
		else
			i++;
	}
	val = ft_substr(temp_line, 0, i);
	if (!val)
		return (ft_print_error(NULL, ERROR_MALLOC_FAIL, NULL, 1), 0);
	token = ft_new_token(val, T_IDENTIFIER);
	if (!token)
		return (free(val), ft_print_error(NULL, ERROR_MALLOC_FAIL, NULL, 1), 0);
	*line += i;
	return (ft_tokens_add_back(tokens, token) && 1);
}

static int	ft_append_tokens(char **line, t_token **tokens)
{
	if (!ft_strncmp(*line, "<<", 2))
		return (ft_append_separator(T_DLESS, line, tokens) && 1);
	else if (!ft_strncmp(*line, ">>", 2))
		return (ft_append_separator(T_DGREATER, line, tokens) && 1);
	else if (!ft_strncmp(*line, "<", 1))
		return (ft_append_separator(T_LESS, line, tokens) && 1);
	else if (!ft_strncmp(*line, ">", 1))
		return (ft_append_separator(T_GREATER, line, tokens) && 1);
	else if (!ft_strncmp(*line, "|", 1))
		return (ft_append_separator(T_PIPE, line, tokens) && 1);
	else
		return (ft_append_identifier(line, tokens) && 1);
}

int	ft_tokenization(t_minishell *shell)
{
	char	*line;

	line = shell->user_input;
	while (*line)
	{
		if ((*line >= 9 && *line <= 13) || *line == 32)
			line++;
		else if (!ft_append_tokens(&line, &(shell->tokens)))
		{
			ft_set_exit(shell, 1);
			return (0);
		}
	}
	shell->current_token = shell->tokens;
	return (1);
}
