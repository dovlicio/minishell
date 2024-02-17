/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:49:30 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/14 12:30:12 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end -1]))
		end--;
	len = end - start;
	trimmed = (char *)malloc((len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}
/*
#include <stdio.h>
int	main()
{
	const char	*s1 = "i   a b c Hello World c b a  i";
	const char	*set = " c b a";
	char		*trimmed = ft_strtrim(s1, set);
	printf("%s\n", trimmed);
	return (0);
}
*/
