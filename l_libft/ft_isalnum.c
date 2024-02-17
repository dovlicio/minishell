/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:11:40 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:30:48 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') \
		|| (c >= '0' && c <= '9'))
		return (8);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("R1: %d\n", ft_isalnum('='));
	printf("R2: %d\n", isalnum('='));
}
*/
