/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:20:44 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/09 12:30:09 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i_includes/minishell.h"

static int	ft_set_token_value(t_token *new)
{
	if (new->type == T_DLESS)
		new->value = ft_strdup("<<");
	else if (new->type == T_DGREATER)
		new->value = ft_strdup(">>");
	else if (new->type == T_GREATER)
		new->value = ft_strdup(">");
	else if (new->type == T_LESS)
		new->value = ft_strdup("<");
	else
		new->value = ft_strdup("|");
	if (!new->value)
		return (ft_print_error(NULL, ERROR_MALLOC_FAIL, NULL, 1), 0);
	return (1);
}

t_token	*ft_new_token(char *t_value, t_token_type t_type)
{
	t_token	*new;

	new = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = t_type;
	if (new->type != T_IDENTIFIER)
	{
		if (!ft_set_token_value(new))
			return (0);
	}
	else
		new->value = t_value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

int	ft_tokens_add_back(t_token **tokens, t_token *new)
{
	t_token	*current;

	if (!*tokens)
	{
		*tokens = new;
		return (1);
	}
	current = *tokens;
	while (current && current->next)
		current = current->next;
	current->next = new;
	new->previous = current;
	return (1);
}

void	ft_clean_tokens(t_token **tokens)
{
	t_token	*current;
	t_token	*next;

	current = *tokens;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*tokens = NULL;
}
