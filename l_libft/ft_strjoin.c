/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:16:00 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/01 07:23:04 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	total_len;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc((total_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	return (new_string);
}
/*
#include <stdio.h>
int	main()
{
	const char	*s1 = "Hello";
	const char	*s2 = "World!";
	char	*new = ft_strjoin(s1, s2);
	printf("Result: %s\n", new);
	return (0);
}
*/
