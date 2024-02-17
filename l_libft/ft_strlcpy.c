/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:18 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/10 17:53:28 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
    char src[] = "Hello, World!";
    char dst_ft[20];
    char dst_strlcpy[20];
    size_t result_ft;
    size_t result_strlcpy;

    result_ft = ft_strlcpy(dst_ft, src, sizeof(dst_ft));
    result_strlcpy = strlcpy(dst_strlcpy, src, sizeof(dst_strlcpy));
    printf("Result 1: ft=%zu, strlcpy=%zu, d1: %s, d2: %s\n",\
		result_ft, result_strlcpy, dst_ft, dst_strlcpy);

    result_ft = ft_strlcpy(dst_ft, src, 5);
    result_strlcpy = strlcpy(dst_strlcpy, src, 5);
    printf("Result 2: ft_strlcpy=%zu, strlcpy=%zu, d1: %s, d2: %s\n",\
		result_ft, result_strlcpy, dst_ft, dst_strlcpy);

    result_ft = ft_strlcpy(dst_ft, src, 0);
    result_strlcpy = strlcpy(dst_strlcpy, src, 0);
    printf("Result 3: ft_strlcpy=%zu, strlcpy=%zu, d1: %s, d2: %s\n",\
		result_ft, result_strlcpy, dst_ft, dst_strlcpy);

    char empty_src[] = "";
    result_ft = ft_strlcpy(dst_ft, empty_src, sizeof(dst_ft));
    result_strlcpy = strlcpy(dst_strlcpy, empty_src, sizeof(dst_strlcpy));
    printf("Result 4: ft_strlcpy=%zu, strlcpy=%zu, d1: %s, d2: %s\n",\
		result_ft, result_strlcpy, dst_ft, dst_strlcpy);
    return 0;
}
*/
