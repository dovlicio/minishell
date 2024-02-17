/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:35:19 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:49:58 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("R1: %d\n", ft_isascii(128));
	printf("R2: %d\n", isascii(128));
	return (0);
}
*/
