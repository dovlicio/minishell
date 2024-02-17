/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:19:16 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/17 14:51:04 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

char	*ft_checker(char *str1, char *str2)
{
	char	*expanded;

	expanded = NULL;
	if (!str1 || !str2)
		return (free(str1), free(str2), NULL);
	expanded = ft_strjoin(str1, str2);
	if (!expanded)
		return (free(str1), free(str2), NULL);
	free(str1);
	free(str2);
	return (expanded);
}

int	ft_expand(t_minishell *shell, char *str, int i)
{
	int		j;
	char	*expanded;

	j = 0;
	expanded = ft_strdup("");
	while (str[j])
	{
		if (str[j] == '\'')
			expanded = ft_checker(expanded, ft_handle_squotes(shell, str, &j));
		else if (str[j] == '"')
			expanded = ft_checker(expanded, ft_handle_dquotes(shell, str, &j));
		else if (str[j] == '$')
			expanded = ft_checker(expanded, ft_handle_dolar(shell, str, &j, 0));
		else
			expanded = ft_checker(expanded, ft_handle_normal_c(shell, str, &j));
		if (!expanded)
			return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	}
	free(shell->cmd_args[i]);
	shell->cmd_args[i] = expanded;
	return (0);
}

int	ft_expand_vars(t_minishell *shell)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (shell->cmd_args[i])
	{
		if (ft_expand(shell, shell->cmd_args[i], i) == -1)
			return (-1);
		i++;
	}
	while (shell->cmd_args[i])
	{
		status = ft_remove_empty(shell, shell->cmd_args[i]);
		if (status == 1)
			continue ;
		else if (status == -1)
			return (-1);
		else
			i++;
	}
	return (0);
}
