/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:11 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:50:24 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*memory;
	unsigned char	character;

	memory = (unsigned char *)s;
	character = (unsigned char)c;
	while (n--)
	{
		if (character == *memory)
			return (memory);
		memory++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main() {
    char str[] = "Hell, wrld!";
    int character_to_find = 'o';
    size_t n = strlen(str);
    void *result = ft_memchr(str, character_to_find, n);

    if (result != NULL) {
        printf("Character found at position: %ld\n", (char *)result - str);
    } else {
        printf("Character not found.\n");
    }

    return 0;
}
*/
