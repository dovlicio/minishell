/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:40:04 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:55:20 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("Result1: %c\n", ft_tolower('A'));
	printf("Result2: %c\n", tolower('A'));
	return (0);
}
*/
