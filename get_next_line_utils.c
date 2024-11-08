/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:12 by matthewjorg       #+#    #+#             */
/*   Updated: 2024/11/08 14:32:26 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if a newline character is present in the given string.
/// @param line The string to be checked for a newline character.
/// @return Returns 1 if a newline character is found, otherwise returns 0.
int	check_newline(char *line)
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