/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:42 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/14 12:11:20 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total_size;
	char	*char_memory;

	total_size = nmemb * size;
	if (nmemb != 0 && size != 0 && total_size / nmemb != size)
		return (NULL);
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	else
	{
		char_memory = (char *)memory;
		while (total_size > 0)
		{
			*char_memory = '\0';
			char_memory++;
			total_size--;
		}
	}
	return (memory);
}
/*
#include <stdio.h>

int main() {
    size_t memory_number = -214748395;
    size_t memory_size = -214748364;

    int *arr = (int *)ft_calloc(memory_number, memory_size);

    if (arr != NULL) {
        for (size_t i = 0; i < memory_number; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    } else {
        printf("Memory allocation failed\n");
    }
    return 0;
}
*/
