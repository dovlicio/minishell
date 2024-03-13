/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:16:18 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/23 18:58:00 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(const char *s)
{
	size_t	lenght;

	lenght = 0;
	if (!s)
		return (0);
	while (s[lenght] != '\0')
		lenght++;
	return (lenght);
}

char	*ft_strchr2(const char *s, int c)
{
	const unsigned char	*s_byte;

	if (!s)
		return (NULL);
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

/* char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	char	*str;
	char	*s1_start;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	s1_start = s1;
	str = (char *)malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		free(s1_start);
		return (NULL);
	}
	i = 0;
	while (*s1 != '\0')
		str[i++] = *(s1)++;
	while (*s2)
		str[i++] = *(s2)++;
	str[i] = '\0';
	free(s1_start);
	return (str);
}
 */