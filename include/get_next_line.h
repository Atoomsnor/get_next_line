/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:30 by roversch          #+#    #+#             */
/*   Updated: 2025/01/04 17:27:24 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

char	*get_next_line(int fd);
static char	*buffer_fills_line(int fd, char *buffer);
// void	*ft_calloc(size_t nmemb, size_t size);
int		main(void);

#endif