/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:15:50 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/01 20:39:05 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_line(char *string)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	trimmed = (char *)malloc(sizeof(char) * (ft_strlen2(string) - i + 1));
	if (!trimmed)
		return (NULL);
	i++;
	j = 0;
	while (string[i])
		trimmed[j++] = string[i++];
	trimmed[j] = '\0';
	free(string);
	return (trimmed);
}

static char	*get_one_line(char *string)
{
	char	*one_line;
	int		i;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] != '\n' && string[i])
		i++;
	if (string[i] == '\n')
		i += 2;
	else if (string[i] == '\0')
		i++;
	one_line = (char *)malloc(i * sizeof(char));
	if (!one_line)
		return (NULL);
	i = 0;
	while (*string && *string != '\n')
		one_line[i++] = *(string)++;
	if (*string == '\n')
		one_line[i++] = '\n';
	one_line[i] = '\0';
	return (one_line);
}

static char	*read_file(int fd, char *string)
{
	char	*temp_string;
	int		bytes_readed;

	bytes_readed = 1;
	temp_string = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_string)
		return (NULL);
	while (!ft_strchr2(string, '\n') && (bytes_readed != 0))
	{
		bytes_readed = read(fd, temp_string, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(string);
			free(temp_string);
			return (NULL);
		}
		temp_string[bytes_readed] = '\0';
		string = ft_strjoin2(string, temp_string);
	}
	free(temp_string);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_file(fd, string);
	if (!string)
		return (NULL);
	one_line = get_one_line(string);
	string = trim_line(string);
	return (one_line);
}
/*
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int	fd = open("binary_file.bin", O_RDONLY);
	//int	fd = 1;
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	int i = 1;
	char *result;
	while (i <= 7)
	{
		result = get_next_line(fd);
		printf("LINE %d: %s\n", i, result);
		i++;
		free(result);
	}
	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (-1);
	}
	return (0);
}
*/
