/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:21:07 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/08 17:45:14 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (f)
			result[i] = f(i, s[i]);
		else
			result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
char sample_function(unsigned int index, char c)
{
    return (char)(c + index);
}

int main()
{
    char input[] = "Hello, World!";
    char *result = ft_strmapi(input, sample_function);

    if (result)
    {
        printf("Result (custom function): %s\n", result);
        free(result);
    }
    else
        printf("ft_strmapi returned NULL.\n");

    char *result2 = ft_strmapi(input, NULL);

    if (result2)
    {
        printf("Result (NULL function): %s\n", result2);
        free(result2);
    }
    else
        printf("ft_strmapi returned NULL.\n");
    return 0;
}
*/
