/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:16 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/19 18:13:43 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *line)
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

int	ft_setnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*ft_trimcarry(char *line, char *carry)
{
	size_t	li;
	size_t	ca;
	char	*re;

	ca = 0;
	li = ft_setnl(line);
	while (line[li + ca] != '\0')
	{
		carry[ca] = line[li + ca];
		ca++;
	}
	re = (char *)malloc(li);
	if (!re)
		return (NULL);
	ca = 0;
	while (ca < li)
	{
		re[ca] = line[ca];
		ca++;
	}
	free(line);
	return (re);
}

char	*ft_extranl(int fd, char *line, char *carry)
{
	ssize_t	bytes;
	char	*temp;

	while (ft_cnewline(line) == 0)
	{
		bytes = read(fd, carry, BUFFER_SIZE + 0);
		if (bytes == -1)
			return (free(line), NULL);
		carry[bytes] = '\0';
		temp = ft_strjoin(line, carry);
		free(line);
		line = ft_strdup(temp);
		free(temp);
		if (!line)
			return (NULL);
		if (bytes == 0)
			break ;
	}
	line = ft_trimcarry(line, carry);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	carry[BUFFER_SIZE + 1];

	if (BUFFER_SIZE + 0 <= 0 || fd < 0 || fd > 1024)
		return (ft_memcpy(carry, "\0", 1), NULL);
	line = ft_strdup(carry);
	if (!line)
		return (NULL);
	line = ft_extranl(fd, line, carry);
	if (!line)
		return (NULL);
	return (line);
}
