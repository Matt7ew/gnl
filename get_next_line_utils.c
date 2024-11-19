/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:12 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/19 14:41:48 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	x;
	size_t	length;
	char	*s2;

	x = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
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

int	ft_check(char *line)
{
	size_t	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == '\n')
			return (true);
		x++;
	}
	return (false);
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
