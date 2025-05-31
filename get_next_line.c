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

/**
 * @brief Reads from the file descriptor and joins the content to the saved string.
 * @param fd The file descriptor to read from.
 * @param saved The string to which the read content will be appended.
 * @return The updated saved string containing the read content, or NULL on error.
 */
static char	*read_and_join(int fd, char *saved)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(saved, buffer);
		free(saved);
		saved = temp;
	}
	free(buffer);
	return (saved);
}

/**
 * @brief Extracts a line from the saved string up to the next newline character.
 * @param saved The string containing the content read from the file descriptor.
 * @return A new string containing the extracted line, or NULL if no line is found.
 */
static char	*extract_line(char *saved)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = ft_substr(saved, 0, i + 1);
	return (line);
}

/**
 * @brief Updates the saved string by removing the extracted line.
 * @param saved The string containing the content read from the file descriptor.
 * @return A new string containing the remaining content after the extracted line, or NULL if no content remains.
 */
static char	*update_saved(char *saved)
{
	int		i;
	char	*new_saved;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	new_saved = ft_substr(saved, i + 1, ft_strlen(saved) - i);
	free(saved);
	return (new_saved);
}

/**
 * @brief Reads a line from the file descriptor, handling static storage for multiple calls.
 * @param fd The file descriptor to read from.
 * @return A new string containing the next line read from the file descriptor, or NULL on error or end of file.
 */
char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
	{
		saved = malloc(1);
		if (!saved)
			return (NULL);
		saved[0] = '\0';
	}
	saved = read_and_join(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	saved = update_saved(saved);
	return (line);
}
