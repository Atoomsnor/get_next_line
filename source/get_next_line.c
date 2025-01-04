/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:22 by roversch          #+#    #+#             */
/*   Updated: 2025/01/04 17:33:10 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <get_next_line.h>
// #include <unistd.h>
// #include <stdio.h>

// #define BUFFER_SIZE 3

// char    *get_next_line(int fd)
// {
// 	static char	*start_point;
// 	char		*line;
// 	char		*buffer;

// 	buffer = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	line = buffer_fills_line(fd, start_point, buffer);
// 	free(buffer);
// 	buffer = NULL;
// 	if (!line)
// 		return (NULL);
// 	return (line);
// }

// static char	*buffer_fills_line(int fd, char *start_point, char *buffer)
// {
// 	int		byte_read;

// 	byte_read = read(fd, buffer, BUFFER_SIZE);
// 	if (byte_read <= 0)
// 	return (NULL);
	

/* A FUNCTION TO GO BACK TO THE STRING THAT HAD A /N AND
THEN GOES TROUGH IT TO SEE WHERE IT ACTUALLY ENDS*/

#include <get_next_line.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
	char	*buffer;
	static	int count = 1;
	char	*line;

	printf("malloc#[%d]---", count++);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = buffer_fills_line(fd, buffer);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
static char	*buffer_fills_line(int fd, char *buffer)
{	
	int	bytes_read;
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}
