/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:03:46 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/14 18:04:59 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_b;
	unsigned char	*src_b;

	dest_b = (unsigned char *)dest;
	src_b = (unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	if (dest_b <= src_b)
	{
		while (n--)
			*dest_b++ = *src_b++;
	}
	else if (dest_b > src_b)
	{
		dest_b += n - 1;
		src_b += n - 1;
		while (n--)
			*dest_b-- = *src_b--;
	}
	return (dest);
}
/*
#include <stdio.h>
int main() {
    char dest[] = "This is a test";
    ft_memmove(dest + 2, dest, 5);
    printf("Destination (right overlap): %s\n", dest);
    return 0;
}
*/
