/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:44:59 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:54:28 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*s_byte;

	s_byte = (const unsigned char *)s;
	if ((unsigned char)c == '\0')
	{
		while (*s_byte != '\0')
			s_byte++;
		return ((char *)s_byte);
	}
	while (*s_byte != '\0')
	{
		if (*s_byte == (unsigned char)c)
			return ((char *)s_byte);
		s_byte++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	const char *str = "Hello, World!";
	int		search = '\0';
	printf("Test string: %s\n", str);
	char *result = ft_strchr(str, search);
	if (result != NULL)
		printf("Character '%c' found at index %ld\n", search, result - str);
	else
		printf("Character '%c' not found\n", search);
	return (0);
}
*/
