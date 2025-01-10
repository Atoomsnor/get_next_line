/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:22 by roversch          #+#    #+#             */
/*   Updated: 2025/01/10 15:43:02 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	static char	*leftovers;
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = buffer_fills_line(fd, leftovers, buffer);
	if (!line)
	{
		free(leftovers);
		leftovers = NULL;
		return (NULL);
	}
	leftovers = find_end(&line);
	return (line);
}

char	*buffer_fills_line(int fd, char *leftovers, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp_leftovers;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(leftovers, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!leftovers)
			leftovers = ft_strdup("");
		if (!leftovers)
			return (NULL);
		temp_leftovers = leftovers;
		leftovers = ft_strjoin(temp_leftovers, buffer);
		free(temp_leftovers);
	}
	return (leftovers);
}

char	*find_end(char **line)
{
	char	*leftovers;
	char	*temp_line;
	size_t	i;

	i = 0;
	if (!*line)
		return (NULL);
	while ((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\0')
		return (NULL);
	leftovers = ft_substr(*line, i + 1, ft_strlen(*line) - i - 1);
	if (!leftovers)
		return (NULL);
	temp_line = ft_substr(*line, 0, i + 1);
	if (*leftovers == '\0' || !temp_line)
	{
		free(leftovers);
		leftovers = NULL;
	}
	free(*line);
	*line = temp_line;
	return (leftovers);
}
