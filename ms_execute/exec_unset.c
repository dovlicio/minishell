/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:14:55 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/13 21:38:52 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_realocate_env(t_minishell *shell, char **new, int *i, int *j)
{
	new[(*j)++] = ft_strdup(shell->envp[(*i)++]);
	if (!new[(*j) - 1])
		return (free_matrix(new), \
				ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	free(shell->envp[(*i) - 1]);
	return (1);
}

static int	ft_get_n1(char *env, char *arg)
{
	int	n1;
	int	n2;

	n1 = ft_strlen_env(env);
	n2 = ft_strlen(arg);
	if (n1 >= n2)
		return (n1);
	return (n2);
}

static char	**ft_delete_env(t_minishell *shell, char *key)
{
	int		i;
	char	**new_envp;
	int		j;

	j = 0;
	while (shell->envp[j])
		j++;
	new_envp = malloc(sizeof(char *) * j);
	if (!new_envp)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), NULL);
	i = 0;
	j = 0;
	while (shell->envp[i])
	{
		if (!ft_strncmp(shell->envp[i], key, ft_get_n1(shell->envp[i], key)))
		{
			free(shell->envp[i++]);
			continue ;
		}
		if (!ft_realocate_env(shell, new_envp, &i, &j))
			return (NULL);
	}
	new_envp[j] = 0;
	free(shell->envp);
	return (new_envp);
}

int	ft_unset(t_minishell *shell)
{
	int	i;
	int	j;

	if (!shell->cmd_args[1] || ft_is_piped(shell))
		return (0);
	i = 1;
	while (shell->cmd_args[i])
	{
		j = 0;
		while (shell->envp[j])
		{
			if (!ft_strncmp(shell->envp[j], shell->cmd_args[i], \
				ft_get_n1(shell->envp[j], shell->cmd_args[i])))
			{
				shell->envp = ft_delete_env(shell, shell->cmd_args[i]);
				if (!shell->envp)
					return (-1);
				break ;
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}
