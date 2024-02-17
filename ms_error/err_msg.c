/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:11:10 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/11 18:51:11 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

void	ft_print_error(t_minishell *shell, char *error, char *str, int status)
{
	if (error)
		ft_putstr_fd("minishell: ", 2);
	if (str)
		(ft_putstr_fd(str, 2), ft_putstr_fd(": ", 2));
	ft_putstr_fd(error, 2);
	if (shell)
		ft_set_exit(shell, status);
}

int	ft_print_syntax_err(t_minishell *shell, char *error, t_token *current)
{
	ft_putstr_fd(error, 2);
	if (!current)
		ft_putstr_fd("newline", 2);
	else
		ft_putstr_fd(current->value, 2);
	ft_putstr_fd("'\n", 2);
	ft_set_exit(shell, 2);
	return (-1);
}
