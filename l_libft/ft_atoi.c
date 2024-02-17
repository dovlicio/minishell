/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:42:27 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/14 12:29:20 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			count_minus;
	long long	result;

	result = 0;
	count_minus = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			count_minus++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	if (result > 0 && (count_minus % 2 != 0))
		result = -result;
	return (result);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	printf("Result: %d\n", ft_atoi("  01234ab543"));
	printf("Result2: %d\n", atoi("   01234ab543"));
	return (0);
}
*/
