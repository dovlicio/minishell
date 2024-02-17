/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:37:40 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/29 16:24:38 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_format(va_list args, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_print_char(va_arg(args, int));
	else if (format == 's')
		result += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		result += ft_print_ptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		result += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		result += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		result += write(1, "%", 1);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		result;

	if (str == NULL)
		return (-1);
	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((ft_strchr("cspdiuxX%", str[i + 1]) != NULL) && str[i + 1])
			{
				result += ft_check_format(args, str[i + 1]);
				i++;
			}
		}
		else
			result += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
