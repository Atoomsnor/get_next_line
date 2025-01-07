/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:20:25 by roversch          #+#    #+#             */
/*   Updated: 2025/01/07 15:12:32 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dup_str = malloc(len + 1);
	if (dup_str == NULL)
		return (NULL);
	while (i < len)
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[len] = '\0';
	return (dup_str);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
