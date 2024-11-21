/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:16 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/21 17:49:33 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	carry[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			bytes;

	bytes = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024 || read(fd, carry, bytes) == -1)
		return (ft_memcpy(carry, "\0", 1), NULL);
	line = ft_strdup(carry);
	if (line == NULL)
		return (NULL);
	line = ft_readl(fd, carry, line, &bytes);
	if (line == NULL)
		return (NULL);
	if (ft_strlen(line) == 0 && bytes == 0)
		return (free(line), NULL);
	temp = ft_line(line);
	return (ft_carry(carry), free(line), temp);
}

char	*ft_readl(int fd, char *carry, char *line, int *bytes)
{
	char	*temp;

	*bytes = 1;
	while (!ft_strchr(line, '\n') && *bytes != 0)
	{
		*bytes = read(fd, carry, BUFFER_SIZE);
		if (*bytes == -1)
			return (free(line), NULL);
		carry[*bytes] = '\0';
		temp = ft_strjoin(line, carry);
		if (!temp)
			return (free(line), NULL);
		free(line);
		line = temp;
	}
	return (line);
}

char	*ft_line(char *line)
{
	char	*l;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
		if (line[i] == '\n')
			l = ft_substr(line, 0, i + 1);
		else
			l = ft_strdup(line);
	}
	return (l);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	size;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	ft_strlcpy(subst, s + start, len + 1);
	return (subst);
}

int	ft_carry(char *Carry)
{
	size_t	i;

	i = 0;
	while (Carry[i] != '\n' && Carry[i] != '\0')
		i++;
	if (Carry[i] == '\n')
	{
		ft_memcpy(Carry, ft_strchr(Carry, '\n') + 1, ft_strlen(ft_strchr(Carry,
					'\n')));
		return (1);
	}
	return (0);
}
