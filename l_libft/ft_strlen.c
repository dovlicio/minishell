/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:52:04 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/10 16:39:26 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}
/*
#include <stdio.h>
int	main()
{
	printf("%zu\n", ft_strlen("abcdef"));
	printf("%zu\n", strlen("abcdef"));
	return (0);
}
*/
