/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:12 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/19 18:15:05 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	y;
	char	*z;

	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1);
	y = ft_strlen(s2);
	z = (char *)malloc(x + y + 1);
	if (!z)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x] != '\0')
	{
		z[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		z[x + y] = s2[y];
		y++;
	}
	z[x + y] = '\0';
	return (z);
}

int	ft_cnewline(char *line)
{
	size_t	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	x;
	size_t	length;
	char	*s2;

	x = 0;
	length = ft_strlen(s1);
	s2 = (char *)malloc(length + 1);
	if (!s2)
		return (NULL);
	while (s1[x] != '\0')
	{
		s2[x] = s1[x];
		x++;
	}
	s2[x] = '\0';
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	if (!dst && !src)
		return (NULL);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
