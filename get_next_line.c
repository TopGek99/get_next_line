/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:47:45 by arowe             #+#    #+#             */
/*   Updated: 2021/10/19 11:47:45 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	end_free(char *mem, int end)
{
	if (end == 0 && mem)
		free(mem);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*temp;
	static char	*line;
	int			end_of_buf;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	end_of_buf = get_buffer(fd, line, BUFFER_SIZE);
	end_free(line, end_of_buf);
	if (end_of_buf == 0)
		return (NULL);
	while (end_of_buf == BUFFER_SIZE)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		end_of_buf = get_buffer(fd, buf, BUFFER_SIZE);
		end_free(buf, end_of_buf);
		if (end_of_buf == 0)
			break ;
		temp = line;
		line = gnl_strjoin(temp, buf);
		free(temp);
		free(buf);
	}
	return (line);
}
