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
#include <stdio.h>

static int	found_newline(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	trim_line(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\n')
		i++;
	while (s[++i])
	{
		s[i] = '\0';
	}
}

char	*get_next_line(int fd)
{
	int		read_result;
	int		contains_newline;
    int     lines_read;
	char	*buf;
	char	*temp;
	char	*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_result = read(fd, line, BUFFER_SIZE);
    line[read_result] = '\0';
	buf = NULL;
    lines_read = 0;
	while (read_result > 0)
	{
		if (!buf)
        {
            buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
            ft_strlcpy(buf, line, BUFFER_SIZE + 1);
        }
		else
		{
			temp = buf;
			buf = ft_strjoin(temp, line);
			free(temp);
		}
		contains_newline = found_newline(buf);
		if (contains_newline >= 0)
		{
			if (contains_newline != BUFFER_SIZE - 1)
				trim_line(buf);
			free(line);
			return (buf);
		}
		ft_bzero(line, BUFFER_SIZE);
		read_result = read(fd, line, BUFFER_SIZE);
        lines_read++;
	}
    if (lines_read > 0)
    {
        free(line);
        return (buf);
    }
    free(line);
	free(buf);
	return (NULL);
}