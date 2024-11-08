/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:16 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/08 14:31:03 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Reads data from a file descriptor.
/// @param fd The file descriptor to read from.
/// @param buf The buffer to store the read data.
/// @param count The number of bytes to read.
/// @return The number of bytes read on success, or -1 on error.
static ssize_t	read(int fd, void *buf, size_t count)
{
	ssize_t	ret;

	ret = read(fd, buf, count);
	return (ret);
}

char	*get_next_line(int fd)
{
	static int	count;
	static char	*line;

	line = NULL;
	line = (char *)malloc(BUFFER_SIZE = 1);
	if (!line)
		return (NULL);
	read(fd, line, BUFFER_SIZE);
	count += BUFFER_SIZE;
	if (check_newline(line))
	{
		return (line);
		free(line);
	}
}
