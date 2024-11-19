/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:16 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/19 14:42:09 by mjorge           ###   ########.fr       */
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
			return (true);
		x++;
	}
	return (false);
}

char	*get_next_line(int fd)
{
	static char	carry[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, carry, 0) == -1 || fd > 1024)
		return (ft_memcpy(carry, "\0", 1), NULL);
	line = ft_strdup(carry);
	if (!line)
		return (NULL);
	line = ft_extranl(fd, line, carry);
	if (!line)
		return (NULL);
	if (ft_check(line))
	{
	}
}

char	*ft_extranl(int fd, char *line, char *carry)
{
	ssize_t	bytes;
	char	*temp;

	while (ft_check(line) == false && (bytes = read(fd, carry, BUFFER_SIZE
				+ 1)))
	{
		if (bytes == -1)
			return (free(line), NULL);
		carry[bytes] = '\0';
		temp = ft_strjoin(line, carry);
		free(line);
		line = ft_strdup(temp);
		free(temp);
		if (!line)
			return (NULL);
	}
	return (line);
}
