/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:35:13 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/23 18:43:41 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates the length of a string.
 * @param s The string to measure.
 * @return The length of the string, or 0 if the string is NULL.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * @brief Locates the first occurrence of a character in a string.
 * @param s The string to search.
 * @param c The character to find.
 * @return A pointer to the first occurrence of the character, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/**
 * @brief Joins two strings into a new dynamically allocated string.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A new string containing the concatenation of s1 and s2, or NULL if memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

/**
 * @brief Extracts a substring from a string.
 * @param s The original string.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A new string containing the substring, or NULL if memory allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
