/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:25:08 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/09 17:55:12 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*s_byte;
	const unsigned char	*last_c;

	s_byte = (const unsigned char *)s;
	last_c = NULL;
	if ((unsigned char)c == '\0')
	{
		while (*s_byte != '\0')
			s_byte++;
		return ((char *)s_byte);
	}
	while (*s_byte != '\0')
	{
		if (*s_byte == (unsigned char)c)
			last_c = s_byte;
		s_byte++;
	}
	if (last_c == NULL)
		return (NULL);
	return ((char *)last_c);
}

/*
#include <stdio.h>

int main() {
    const char *testString = "He\0ll, Wrld!";
    int searchChar = '\0';

    printf("Test String: %s\n", testString);

    // Use your strrchr function
    char *result = ft_strrchr(testString, searchChar);

    if (result != NULL) {
        printf("Character '%c' found at position %ld\n", \
			searchChar, result - testString);
    } else {
        printf("Character '%c' not found\n", searchChar);
    }

    return 0;
}
*/
