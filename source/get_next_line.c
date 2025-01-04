/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:22 by roversch          #+#    #+#             */
/*   Updated: 2025/01/04 15:11:02 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 3

char    *get_next_line(int fd)
{
	static char	*start_point;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = buffer_fills_line(fd, start_point, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	return (line);
}

static char	*buffer_fills_line(int fd, char *start_point, char *buffer)
{
	int		byte_read;

	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read <= 0)
	return (NULL);
	

/* A FUNCTION TO GO BACK TO THE STRING THAT HAD A /N AND
THEN GOES TROUGH IT TO SEE WHERE IT ACTUALLY ENDS*/


char *get_next_line(int fd)
{
 int   bytes_read;
 char  *buffer;
 static int count = 1;

 printf("malloc#[%d]---", count++);
 cup_buffer = malloc (3 + 1, sizeof(char));
 if (cup_buffer == NULL)
  return (NULL);
 bytes_read = read(fd, cup_buffer, 3);
 if (bytes_read <= 0)
  return (NULL);
 return (cup_buffer);
}