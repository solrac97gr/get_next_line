/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:35:08 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/23 18:43:41 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

/**
* @brief Reads a line from a file descriptor.
* @param fd The file descriptor to read from.
* @return A pointer to the line read, or NULL 
* if an error occurs or EOF is reached.
*/
char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes_read;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	line = strdup(buffer);
	free(buffer);
	return (line);
}
