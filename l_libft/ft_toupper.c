/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:30:06 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:55:25 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("Result1: %c\n", ft_toupper('='));
	printf("Result2: %c\n", toupper('='));
	return (0);
}
*/
