/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:29:15 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/29 16:25:40 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(unsigned int num)
{
	int	result;

	result = 0;
	while (num != 0)
	{
		result++;
		num = num / 10;
	}
	return (result);
}

static char	*ft_uitoa(unsigned int num)
{
	char	*number;
	int		len;

	len = ft_num_len(num);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len] = '\0';
	while (num != 0)
	{
		number[len - 1] = num % 10 + 48;
		num = num / 10;
		len--;
	}
	return (number);
}

int	ft_print_unsigned(unsigned int num)
{
	int		result;
	char	*number;

	result = 0;
	if (num == 0)
		result += write(1, "0", 1);
	else
	{
		number = ft_uitoa(num);
		result += ft_print_str(number);
		free(number);
	}
	return (result);
}
