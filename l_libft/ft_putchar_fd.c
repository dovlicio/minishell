/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:16:57 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/08 19:22:17 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd == -1)
    {
        perror("Failed to open file");
        return 1;
    }
    ft_putchar_fd('H', fd);
    ft_putchar_fd('e', fd);
    ft_putchar_fd('l', fd);
    ft_putchar_fd('l', fd);
    ft_putchar_fd('o', fd);

    close(fd);

    return 0;
}
*/
