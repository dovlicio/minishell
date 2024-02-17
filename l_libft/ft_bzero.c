/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:47:56 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:30:26 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_bytes;

	s_bytes = s;
	while (n > 0)
	{
		*s_bytes = '\0';
		s_bytes++;
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char	buffer[20];
	char	expected[20] = {0};
	size_t	buffer_size = sizeof(buffer);
	strcpy(buffer, "Hello, world!");
	printf("Buffer before ft_bzero:\n");
	for (size_t i = 0; i < buffer_size; i++) {
		printf("%c ", buffer[i]);
	}
	printf("\n");
	ft_bzero(buffer, buffer_size);
	printf("Buffer after ft_bzero:\n");
	for (size_t i = 0; i < buffer_size; i++) {
		printf("%c ", buffer[i]);
	}
	printf("\n");
	if (memcmp(buffer, expected, buffer_size) == 0)
		printf("Buffer is corectly zeroed.\n");
	else
		printf("Buffer is not zeroed as expected.\n");
	return (0);
}
*/
