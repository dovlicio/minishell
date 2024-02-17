/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:37:06 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/17 14:59:59 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*sub_start;

	if (s == NULL || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub_start = sub;
	while (len--)
		*sub++ = s[start++];
	*sub = '\0';
	return (sub_start);
}
/*
#include <stdio.h>

int	main()
{
	const char	*s = "Hello World!";
	char	*sub = ft_substr(s, 4, 6);
	printf("%s\n", sub);
	return (0);
}
*/
