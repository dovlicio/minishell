/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:35:37 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 12:07:53 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(const char *s, char c)
{
	int	number_of_words;
	int	count_next;

	number_of_words = 0;
	count_next = 0;
	while (*s)
	{
		if (*s == c)
			count_next = 0;
		else if (count_next == 0)
		{
			count_next = 1;
			number_of_words++;
		}
		s++;
	}
	return (number_of_words);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	i;

	copy = (char *)ft_calloc(sizeof(char), n + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**free_all(char	**array, int index)
{
	int	i;

	i = 0;
	while (i < index)
		free(array[i++]);
	free(array);
	return (NULL);
}

char	**put_zero(char **array, int index)
{
	array[index] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	const char	*start;
	int			i;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc(sizeof(char *), (count_strings(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i++] = ft_strndup(start, s - start);
			if (!result[i - 1])
				return (free_all(result, i - 1));
		}
		else
			s++;
	}
	return (put_zero(result, i));
}
/*
#include <stdio.h>
int main()
{
    char const *array = " acb acb afab ceda bcefa ";
    char **strings = ft_split(array, ' ');
    
    if (strings)
    {
        int i = 0;
        while (strings[i])
        {
            printf("%s\n", strings[i]);
            free(strings[i]);
            i++;
        }
        free(strings);
    }
    return 0;
}
*/
