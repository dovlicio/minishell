/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:03:54 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 18:58:32 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static void	ft_skip_and_count(char *str, int *i, int *plus, int *minus)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			(*minus)++;
		else if (str[*i] == '+')
			(*plus)++;
		(*i)++;
	}
}

static int	ft_check_digit(char *str)
{
	int	i;
	int	plus;
	int	minus;

	i = 0;
	plus = 0;
	minus = 0;
	if (ft_strlen(str) == 2 && str[0] == '-' && str[1] == '-' && !str[2])
		return (0);
	if (!str[i])
		return (-1);
	ft_skip_and_count(str, &i, &plus, &minus);
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0' && plus < 2 && minus < 2)
		return (0);
	return (-1);
}

static int	ft_check_exit_args(t_minishell *shell)
{
	int	i;

	if (ft_check_digit(shell->cmd_args[1]) == -1)
	{
		if (!ft_is_piped(shell))
			(write(2, "exit\n", 5), \
			ft_print_error(shell, ERROR_NUMERIC_REQUIRED, "exit: ", 2), \
			ft_clean_all(shell, 2, NULL));
		return (ft_print_error(shell, ERROR_NUMERIC_REQUIRED, "exit: ", 2), -1);
	}
	i = 0;
	while (shell->cmd_args[i])
		i++;
	if (i > 2 && !ft_is_piped(shell))
		return (-1);
	else if (i > 2)
		return (ft_print_error(shell, ERROR_TOO_MANY_ARGS, "exit: ", 1), -1);
	return (0);
}

static void	ft_calc_exit(int *exit)
{
	if (*exit < 0)
	{
		*exit = *exit % 256;
		*exit = -(*exit);
		*exit = 256 - *exit;
	}
	else if (*exit > 256)
	{
		*exit = *exit % 256;
		*exit = 0 + *exit;
	}
}

int	ft_exit(t_minishell *shell)
{
	int	exit;

	if (g_exit == 1)
		exit = 130;
	else
		exit = shell->exit_status;
	if (!shell->cmd_args[1])
	{
		if (!ft_is_piped(shell))
			(ft_putstr_fd("exit\n", 1), ft_clean_all(shell, exit, NULL));
		return (0);
	}
	if (ft_check_exit_args(shell) == -1)
	{
		if (!ft_is_piped(shell))
			return (ft_print_error(shell, ERROR_TOO_MANY_ARGS, \
					"exit: ", 1), -1);
		return (-1);
	}
	exit = ft_atoi(shell->cmd_args[1]);
	ft_calc_exit(&exit);
	if (!ft_is_piped(shell))
		(ft_putstr_fd("exit\n", 1), ft_clean_all(shell, exit, NULL));
	return (ft_set_exit(shell, exit), -1);
}
