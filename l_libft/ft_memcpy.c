/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:21:27 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/14 18:04:49 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_byte;
	const unsigned char	*src_byte;

	dest_byte = (unsigned char *)dest;
	src_byte = (const unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	while (n > 0)
	{
		*dest_byte = *src_byte;
		n--;
		dest_byte++;
		src_byte++;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	
	void *source = "Hello World";
	char destination[20];

	ft_memcpy(destination, source, source_size);
	printf("Copied string: %s\n", destination);
	if (memcmp(destination, source, 5) == 0)
		printf("Data has been copied correctly.\n");
	else
		printf("Data has not been copied correctly. \n");
	return (0);
}
*/
