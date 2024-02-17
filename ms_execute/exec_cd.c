/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:12:38 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/14 15:13:38 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_set_old_pwd(t_minishell *shell, char *pwd, char *old_pwd, int *i)
{
	free(shell->envp[*i]);
	shell->envp[*i] = ft_strjoin("OLDPWD=", old_pwd);
	if (!shell->envp[*i])
		return (free(old_pwd), free(pwd), \
				ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	return (1);
}

static int	ft_set_pwd(t_minishell *shell, char *pwd, char *old_pwd, int *i)
{
	free(shell->envp[*i]);
	shell->envp[*i] = ft_strjoin("PWD=", pwd);
	if (!shell->envp[*i])
		return (free(old_pwd), free(pwd), \
				ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	return (1);
}

static int	ft_change_pwds(t_minishell *shell, char *old_pwd)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (free(old_pwd), \
				ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	while (shell->envp[i])
	{
		if (!ft_strncmp(shell->envp[i], "OLDPWD", 6) && \
			shell->envp[i][6] == '=')
		{
			if (!ft_set_old_pwd(shell, pwd, old_pwd, &i))
				return (-1);
		}
		else if (!ft_strncmp(shell->envp[i], "PWD", 3) && \
			shell->envp[i][3] == '=')
		{
			if (!ft_set_pwd(shell, pwd, old_pwd, &i))
				return (-1);
		}
		i++;
	}
	return (free(pwd), free(old_pwd), 1);
}

static int	ft_check_cd(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->cmd_args[i])
		i++;
	if (i > 2)
		return (ft_print_error(shell, ERROR_TOO_MANY_ARGS, NULL, 1), -1);
	return (0);
}

int	ft_cd(t_minishell *shell)
{
	char	*home_path;
	char	*old_pwd;

	if (ft_is_piped(shell))
		return (0);
	if (ft_check_cd(shell) == -1)
		return (ft_set_exit(shell, -1));
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (ft_print_error(shell, ERROR_MALLOC_FAIL, NULL, 1), -1);
	home_path = ft_extract_env_value(shell->envp, "HOME");
	if (!home_path)
		return (free(old_pwd), ft_print_error(shell, ERR_NH, "cd", 1), -1);
	if (!shell->cmd_args[1])
	{
		if (chdir(home_path) != 0)
			return (ft_print_error(shell, ERROR_NO_SUCH_FILE, NULL, 1), \
					free(old_pwd), ft_set_exit(shell, -1));
	}
	else if (chdir(shell->cmd_args[1]) != 0)
		return (ft_print_error(shell, ERROR_NO_SUCH_FILE, NULL, 1), \
				free(old_pwd), ft_set_exit(shell, -1));
	if (!ft_change_pwds(shell, old_pwd))
		return (-1);
	return (0);
}
