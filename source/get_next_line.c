/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:22 by roversch          #+#    #+#             */
/*   Updated: 2025/01/07 16:52:18 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3 // remove this later as it will be compiled with

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftovers);
		free(buffer);
		leftovers = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = buffer_fills_line(fd, leftovers, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftovers = find_end(line);
	return (line);
}

char	*buffer_fills_line(int fd, char *leftovers, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp_buffer;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftovers);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!leftovers)
			leftovers = ft_strdup("");
		temp_buffer = leftovers;
		leftovers = ft_strjoin(temp_buffer, buffer);
		free(temp_buffer);
		temp_buffer = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftovers);
}

char	*find_end(char *line)
{
	char	*leftovers;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	leftovers = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*leftovers == 0)
	{
		free(leftovers);
		leftovers = NULL;
	}
	line[i + 1] = '\0';
	return (leftovers);
}
