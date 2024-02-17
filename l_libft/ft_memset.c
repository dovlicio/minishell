/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:51:09 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 18:36:04 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_byte;
	unsigned char	*p_start;

	p_start = (unsigned char *)s;
	p_byte = (unsigned char *)s;
	while (n > 0)
	{
		*p_byte = (unsigned char)c;
		n--;
		p_byte++;
	}
	return (p_start);
}
/*
#include <stdio.h>
int	main()
{
	char	buffer[20];
	char	expected[20];
	size_t	buffer_size = sizeof(buffer);
	char	fill_value = 'A';

	ft_memset(buffer, fill_value, buffer_size);

	printf("Buffer after ft_memset:\n");
	for (size_t i = 0; i < buffer_size; i++) {
		printf("%c ", buffer[i]);
	}
	printf("\n");

	memset(expected, fill_value, buffer_size);

	if (memcmp(buffer, expected, buffer_size) == 0)
		printf("Buffer matches the expected pattern.\n");
	else
		printf("Buffer doesn not match expected pattern.\n");
	return (0);
}
*/
