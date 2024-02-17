/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:20:57 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/29 16:25:13 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	result;

	result = 0;
	while (num != 0)
	{
		result++;
		num = num / 16;
	}
	return (result);
}

static void	ft_hex_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_hex_ptr(num / 16);
		ft_hex_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(uintptr_t ptr)
{
	int	result;

	result = 0;
	if (ptr == 0)
		result += write(1, "(nil)", 5);
	else
	{
		result += write(1, "0x", 2);
		ft_hex_ptr(ptr);
		result += ft_ptr_len(ptr);
	}
	return (result);
}
