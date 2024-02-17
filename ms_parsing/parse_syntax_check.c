/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:33:02 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/08 20:14:46 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

int	ft_check_syntax_errors(t_minishell *shell)
{
	t_token	*tmp;

	tmp = shell->tokens;
	if (tmp && tmp->type == T_PIPE)
		return (ft_print_syntax_err(shell, ERROR_WRONG_SYNTAX, \
				tmp));
	while (tmp)
	{
		if (tmp->type == T_PIPE && !tmp->next)
			return (ft_print_syntax_err(shell, ERROR_WRONG_SYNTAX, \
					tmp));
		if (tmp->type != T_IDENTIFIER && tmp->type != T_PIPE && \
			(!tmp->next || tmp->next->type != T_IDENTIFIER))
			return (ft_print_syntax_err(shell, \
					ERROR_WRONG_SYNTAX, tmp->next));
		tmp = tmp->next;
	}
	return (0);
}
