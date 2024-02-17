/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_empty_dolar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:34:12 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/11 13:41:06 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_quote_exists(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	ft_remove_empty(t_minishell *shell, char *str)
{
	int		j;
	char	*copy;

	j = 0;
	if (str[j] == '$' && !ft_quote_exists(str) && \
		!ft_strchr(&str[j + 1], '@') && str[j + 1] != '?' && \
		!ft_extract_env_value(shell->envp, &str[j + 1]) && str[j + 1])
	{
		copy = ft_strdup(str);
		if (!copy)
			return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
		shell->cmd_args = ft_delete_arg(shell, copy);
		if (!shell->cmd_args)
			return (-1);
		free(copy);
		return (1);
	}
	return (0);
}
