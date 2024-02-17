/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:47:08 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/08 18:16:08 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !(*s) || !f)
		return ;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
/*
#include <stdio.h>

void print_char_and_index(unsigned int index, char *c)
{
    printf("Character at index %u: %c\n", index, *c);
}

int main()
{
    char input[] = "Hello, World!";

    printf("Original string: %s\n", input);
    printf("Applying ft_striteri:\n");
    ft_striteri(input, print_char_and_index);
    return 0;
}
*/
