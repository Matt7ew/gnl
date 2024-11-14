/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:16 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/14 14:00:24 by mjorge           ###   ########.fr       */
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
	static char	line[BUFFER_SIZE + 1];
	int			count;
	char		*return_line;

	return_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	read(fd, return_line, BUFFER_SIZE + 1);
	if (check_newline(return_line))
	{
		return (return_line);
	}
}
