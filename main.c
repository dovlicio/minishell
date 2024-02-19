/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 06:59:32 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/19 17:19:18 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "i_includes/minishell.h"

int	g_exit;

int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;

	ft_init_shell(&shell, argc, argv, envp);
	while (1)
	{
		ft_signals();
		ft_init_prompt(&shell);
		if (ft_tokenization(&shell) && ft_parse(&shell) != -1)
			ft_execute(&shell);
		ft_clean(&shell);
	}
	return (0);
}
