/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:04:11 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 16:14:54 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_shlvl_helper(t_minishell *shell, char *new_lvl)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], "SHLVL=", 6) == 0)
		{
			free(shell->envp[i]);
			shell->envp[i] = new_lvl;
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_shlvl(t_minishell *shell, char *path, int what)
{
	int		lvl;
	char	*new_lvl;

	if (ft_strncmp(path, "./minishell", 1000) == 0)
	{
		if (what == 1)
		{
			lvl = ft_atoi(ft_extract_env_value(shell->envp, "SHLVL")) + 1;
			signal(SIGINT, SIG_IGN);
		}
		else
			lvl = ft_atoi(ft_extract_env_value(shell->envp, "SHLVL")) - 1;
		new_lvl = ft_checker(ft_strdup("SHLVL="), ft_itoa(lvl));
		new_lvl = ft_checker(new_lvl, ft_strdup("\n"));
		if (!new_lvl)
			return ;
		if (ft_shlvl_helper(shell, new_lvl) == 0)
			return ;
	}
	return (ft_child_signals());
}
