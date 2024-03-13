/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:47:27 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 15:50:00 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static t_heredocs	*ft_new_heredoc(int fd)
{
	t_heredocs	*new;

	new = (t_heredocs *)ft_calloc(1, sizeof(t_heredocs));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static void	ft_heredoc_add_back(t_heredocs **heredocs, t_heredocs *new)
{
	t_heredocs	*current;

	if (!*heredocs)
	{
		*heredocs = new;
		return ;
	}
	current = *heredocs;
	while (current && current->next)
		current = current->next;
	current->next = new;
}

void	ft_clean_heredocs(t_heredocs **heredocs)
{
	t_heredocs	*current;
	t_heredocs	*next;

	current = *heredocs;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*heredocs = NULL;
}

static int	ft_open_heredoc(t_minishell *shell, char *file)
{
	int			r_fd;
	int			w_fd;
	t_heredocs	*new;

	g_exit = 0;
	w_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (w_fd == -1)
		return (ft_print_error(shell, ERROR_FILE_OPEN_FAILED, file, 1), -1);
	r_fd = open(file, O_RDWR, 0666);
	if (r_fd == -1)
		return (ft_print_error(shell, ERROR_NO_SUCH_FILE, file, 1), -1);
	if (unlink(file) == -1)
		return (close(r_fd), -1);
	if (ft_read_input(shell, file, w_fd) == -1)
		return (close(r_fd), -1);
	new = ft_new_heredoc(r_fd);
	if (!new)
		return (ft_clean_heredocs(&shell->heredoc_list), -1);
	ft_heredoc_add_back(&shell->heredoc_list, new);
	return (0);
}

int	ft_init_heredocs(t_minishell *shell)
{
	t_token	*tmp;
	int		status;

	status = 0;
	if (!shell->current_token)
		return (-1);
	tmp = shell->current_token->next;
	while (tmp)
	{
		if (ft_strncmp(tmp->previous->value, "<<", 3) == 0)
			status = ft_open_heredoc(shell, tmp->value);
		if (status == -1)
			return (-1);
		tmp = tmp->next;
	}
	shell->current_heredoc = shell->heredoc_list;
	return (0);
}
