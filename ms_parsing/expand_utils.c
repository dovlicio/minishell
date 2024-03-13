/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:18:53 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 15:08:25 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

char	*ft_handle_squotes(t_minishell *shell, char *str, int *j)
{
	char	*expanded;
	int		start;

	(void)shell;
	expanded = NULL;
	(*j)++;
	start = *j;
	while (str[*j] != '\'')
		(*j)++;
	expanded = ft_substr(str, start, *j - start);
	(*j)++;
	return (expanded);
}

char	*ft_handle_normal_c(t_minishell *shell, char *str, int *j)
{
	char	*expanded;
	int		start;

	(void)shell;
	expanded = NULL;
	start = *j;
	while (str[*j] && !ft_strchr("$\"'", str[*j]))
		(*j)++;
	expanded = ft_substr(str, start, *j - start);
	return (expanded);
}

static char	*ft_dolar_helper(t_minishell *shell, char *str, int *start, int *j)
{
	if (str[(*j)] == '?')
	{
		if (g_exit == 1)
			return ((*j)++, ft_itoa(130));
		return ((*j)++, ft_itoa(shell->exit_status));
	}
	if (!ft_isalnum(str[*j]) && str[*j] != '_')
		return ((*j)++, ft_strdup(""));
	*start = *j;
	while (ft_isalnum(str[*j]) || str[*j] == '_')
		(*j)++;
	return (NULL);
}

char	*ft_handle_dolar(t_minishell *shell, char *str, int *j, int d)
{
	char	*expanded;
	char	*env;
	int		start;

	if (!d && (str[(*j) + 1] && ft_strchr("\"'", str[(*j) + 1])))
		return ((*j)++, ft_strdup(""));
	if (!str[(*j) + 1] || (!ft_isalnum(str[*j + 1]) && \
		!ft_strchr("?_", str[*j + 1])))
		return ((*j)++, ft_strdup("$"));
	if (!str[(*j) + 1] || (ft_strchr("\"'", str[(*j) + 1]) && !str[(*j) + 2]))
		return ((*j)++, ft_strdup("$"));
	if (!str[(*j) + 1] || (ft_strchr("\"'", str[(*j) + 1]) && str[(*j) + 2]))
		return ((*j)++, ft_strdup(""));
	if (str[(*j)++] == '@' || ft_isdigit(str[*j]))
		return ((*j)++, ft_strdup(""));
	expanded = ft_dolar_helper(shell, str, &start, j);
	if (expanded)
		return (expanded);
	env = ft_substr(str, start, *j - start);
	if (!env)
		return (NULL);
	if (!ft_extract_env_value(shell->envp, env))
		return (free(env), ft_strdup(""));
	expanded = ft_strdup(ft_extract_env_value(shell->envp, env));
	return (free(env), expanded);
}

char	*ft_handle_dquotes(t_minishell *shell, char *str, int *j)
{
	char	*expanded;
	int		start;

	expanded = ft_strdup("");
	(*j)++;
	start = *j;
	while (str[*j] != '"')
	{
		if (str[*j] == '$')
		{
			expanded = ft_checker(expanded, ft_substr(str, start, *j - start));
			expanded = ft_checker(expanded, ft_handle_dolar(shell, str, j, 1));
			if (!expanded)
				return (NULL);
			start = *j;
		}
		else
			(*j)++;
	}
	expanded = ft_checker(expanded, ft_substr(str, start, *j - start));
	if (!expanded)
		return (NULL);
	(*j)++;
	return (expanded);
}
