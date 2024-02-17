/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:14:53 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/10 12:26:55 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (((i + j) < len) && big[i + j] && little[j] && \
			(big[i + j] == little[j]))
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&(big[i]));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main() {
    const char *testString = "see FF your FF return FF now FF";
    const char *substring = "FF";
    size_t maxLen = ft_strlen(testString);

    printf("Test String: %s\n", testString);

    char *result = ft_strnstr(testString, substring, maxLen);

    if (result != NULL) {
        printf("Substring '%s' found at position %ld\n", \
			substring, result - testString);
    } else {
        printf("Substring '%s' not found\n", substring);
    }
    return 0;
}
*/
