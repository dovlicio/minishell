/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:15:14 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 12:05:30 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	if (!s)
		return (NULL);
	while (s[size])
		size++;
	dest = (char *)ft_calloc(sizeof(char), size + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main() {
    const char *originalString = "Hello, World!";
    
    // Use your ft_strdup function
    char *duplicateString = ft_strdup(originalString);

    if (duplicateString != NULL) {
        printf("Original: %s\n", originalString);
        printf("Duplicate: %s\n", duplicateString);

        // Clean up memory by freeing the duplicate string
        free(duplicateString);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
