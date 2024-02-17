/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:35:32 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/29 16:25:26 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int number)
{
	int	result;

	result = 0;
	while (number != 0)
	{
		result++;
		number = number / 16;
	}
	return (result);
}

static void	ft_put_hex(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_put_hex(number / 16, format);
		ft_put_hex(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((number - 10 + 'a'), 1);
			else
				ft_putchar_fd((number - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int number, const char format)
{
	if (number == 0)
		return (write(1, "0", 1));
	ft_put_hex(number, format);
	return (ft_hex_len(number));
}
