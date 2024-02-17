/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:36:04 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 14:38:47 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
	}
}
/*
#include <stdio.h>
int main(void)
{
    char *str = "Hello, World!\n";
    int fd = STDOUT_FILENO;

    ft_putstr_fd(str, fd);

    return (0);
}
*/
