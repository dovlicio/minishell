/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:43:42 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/10 17:40:07 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*memory1;
	unsigned char	*memory2;

	memory1 = (unsigned char *)s1;
	memory2 = (unsigned char *)s2;
	while (n)
	{
		if (*memory1 != *memory2)
			return (*memory1 - *memory2);
		memory1++;
		memory2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
int main() {

    char str1[] = "1111122222";
    char str2[] = "111111";
    int result1 = ft_memcmp(str1, str2, 10);
    int result2 = memcmp(str1, str2, 10);
    printf("Test Case 1: %d\n", result1);
    printf("Test Case 1: %d\n", result2);

    char str3[] = "Hello, World!";
    char str4[] = "Goodbye, World!";
    int result3 = ft_memcmp(str3, str4, strlen(str3));
    int result4 = memcmp(str3, str4, strlen(str3));
    printf("Test Case 2: %d\n", result3);
    printf("Test Case 2: %d\n", result4);

    char str5[] = "Hello, World!";
    char str6[] = "Hello, Universe!";
    int result5 = ft_memcmp(str5, str6, 7);
    int result6 = memcmp(str5, str6, 7);
    printf("Test Case 3: %d\n", result5);
    printf("Test Case 3: %d\n", result6);

    char str7[] = "Hello, World!";
    char str8[] = "Hello";
    int result7 = ft_memcmp(str7, str8, strlen(str7));
    int result8 = memcmp(str7, str8, strlen(str7));
    printf("Test Case 4: %d\n", result7);
    printf("Test Case 4: %d\n", result8);

    return 0;
}
*/
