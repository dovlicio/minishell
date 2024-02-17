/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:17:54 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/11 16:03:58 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	const char *s1 = "abcdef";
	const char *s2 = "abc\375xx";
	printf("Result1: %d\n", ft_strncmp(s1, s2, 5));
	printf("Result2: %d\n", strncmp(s1, s2, 5));
	return (0);
}
*/
