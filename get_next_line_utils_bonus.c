/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:47:45 by arowe             #+#    #+#             */
/*   Updated: 2021/10/19 11:47:45 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (0);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		join[i] = s2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

int	get_buffer(int fd, char *buf, int buf_size)
{
	int		read_result;
	int		i;

	i = 1;
	read_result = read(fd, buf, 1);
	if (read_result < 1)
	{
		buf = NULL;
		return (0);
	}
	while (buf[i - 1] != '\n' && read_result > 0 && i < buf_size)
	{
		read_result = read(fd, buf + i, 1);
		if (read_result > 0)
			i++;
	}
	buf[i] = '\0';
	if (buf[i - 1] == '\n' && i == buf_size)
		i++;
	return (i);
}
