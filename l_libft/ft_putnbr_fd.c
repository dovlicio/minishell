/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:47:33 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/11 10:58:27 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_num_fd(char n, int fd)
{
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_num_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_num_fd((n % 10) + '0', fd);
}
/*
#include <stdio.h>
int main(void)
{
    int fd = STDOUT_FILENO;

    ft_putnbr_fd('A', fd);
    ft_putchar_num_fd('\n', fd);
    ft_putnbr_fd(123, fd);
    ft_putchar_num_fd('\n', fd);
    ft_putnbr_fd(2147483647, fd);
    ft_putchar_num_fd('\n', fd);
    ft_putnbr_fd(0, fd);
    ft_putchar_num_fd('\n', fd);
    ft_putnbr_fd(-2147483648, fd);
    ft_putchar_num_fd('\n', fd);
    return (0);
}
*/
