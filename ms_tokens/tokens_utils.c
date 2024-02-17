/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:21:07 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/01 07:21:17 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	ft_skip_quotes(char *line, size_t *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + *i + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (1);
	}
	return (0);
}
