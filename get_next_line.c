/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:35:08 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/21 17:16:12 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*get_next_line(int fd)
{
	int		len;
	char	*buff[BUFFER_SIZE];


	printf("GET NEXT LINE START")
	len = 0;
	len = read(fd, buff, len);
	while (*buff)
	{
		len--;
		return (char *)buff[len-1];
	}
	printf("GET NEXT LINE END")
	return (NULL);
}
