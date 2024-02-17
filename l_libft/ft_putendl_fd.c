/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:39:46 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 14:47:10 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}
/*
#include <stdio.h>
int main(void)
{
    char *str = "Hello, World!";
    int fd = STDOUT_FILENO;

    ft_putendl_fd(str, fd);

    return (0);
}
*/
