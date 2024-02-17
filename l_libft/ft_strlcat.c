/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:47:32 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/14 18:04:32 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = ft_strlen(src);
	if (dst == 0 || size == 0)
		return (src_len);
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len < size)
	{
		i = 0;
		while (src[i] && i < (size - dest_len - 1))
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
    char dst_ft[20];
    char dst_strlcat[20];
    const char *src = "Hello, World!";
    size_t result_ft;
    size_t result_strlcat;

    memset(dst_ft, 0, sizeof(dst_ft));
    memset(dst_strlcat, 0, sizeof(dst_strlcat));

    strncpy(dst_ft, "Hello, ", sizeof(dst_ft) - 1);
    strncpy(dst_strlcat, "Hello, ", sizeof(dst_strlcat) - 1);

    result_ft = ft_strlcat(dst_ft, src, sizeof(dst_ft));
    result_strlcat = strlcat(dst_strlcat, src, sizeof(dst_strlcat));
    printf("Result 1: ft_strlcat=%zu, strlcat=%zu, d1: %s, d2: %s\n",\
		result_ft, result_strlcat, dst_ft, dst_strlcat);

    memset(dst_ft, 0, sizeof(dst_ft));
    memset(dst_strlcat, 0, sizeof(dst_strlcat));
    strncpy(dst_ft, "Hello, ", sizeof(dst_ft) - 1);
    strncpy(dst_strlcat, "Hello, ", sizeof(dst_strlcat) - 1);

    result_ft = ft_strlcat(dst_ft, src, 5);
    result_strlcat = strlcat(dst_strlcat, src, 5);
    printf("Result 2: ft_strlcat=%zu, strlcat=%zu, d1: %s, d2: %s\n",\
		result_ft, result_strlcat, dst_ft, dst_strlcat);

    return 0;
}
*/
