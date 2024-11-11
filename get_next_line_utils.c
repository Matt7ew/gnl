/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:12 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/11 22:46:33 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Counts the length of a string until a \0 character is encountered.
/// @param s The string whose length is to be calculated.
/// @return The length of the string up to the newline or null character.
size_t	ft_strlenn(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

/// @brief Calculates the length of a string until the null character is encountered.
/// @param s The string whose length is to be calculated.
/// @return The length of the string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
