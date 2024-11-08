/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:16 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/07 17:32:11 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Reads data from a file descriptor.
/// @param fd The file descriptor to read from.
/// @param buf The buffer to store the read data.
/// @param count The number of bytes to read.
/// @return The number of bytes read on success, or -1 on error.
static ssize_t read(int fd, void *buf, size_t count)
{
	ssize_t ret;
	ret = read(fd, buf, count);
	return (ret);
}
int check_newline(char *line)
{
	int i;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static int count;
	static char *line;
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
