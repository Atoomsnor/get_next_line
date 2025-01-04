/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:25 by roversch          #+#    #+#             */
/*   Updated: 2025/01/04 15:46:51 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

// static char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (c == '\0')
// 		return ((char *)s);
// 	return (0);
// }
