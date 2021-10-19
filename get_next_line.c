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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

static char *first_line(char *s)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(s));
	i = 0;
	new[i] = s[i];
	i++;
	while (s[i - 1] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*temp;
	int			read_result;	
	int			i;
	int			contain_new_line;

	line = malloc(BUFFER_SIZE * sizeof(char));
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!line || !buf)
		return (NULL);
	contain_new_line = 0;
	read_result = 1;
	while (!contain_new_line && read_result > 0)
	{
		i = 0;
		read_result = read(fd, line, BUFFER_SIZE);
		if (read_result <= 0)
			break ;
		if (ft_strchr(line, '\n'))
		{
			contain_new_line = 1;
			temp = line;
			line = first_line(line);
			free(temp);
		}
		if (!buf)
			buf = ft_strdup("");
		temp = buf;
		buf = ft_strjoin(buf, line);
		free(temp);
		ft_bzero(line, BUFFER_SIZE);
	}
	free(line);
	if (read_result <= 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}