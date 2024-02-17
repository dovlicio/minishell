/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:51:40 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/24 18:57:40 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
