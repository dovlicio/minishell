/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:05:58 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:50:17 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("R1: %d\n", ft_isprint('z'));
	printf("R2: %d\n", isprint('='));
	return (0);
}
*/
