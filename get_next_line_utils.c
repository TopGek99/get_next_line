/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:47:45 by arowe             #+#    #+#             */
/*   Updated: 2021/10/19 11:47:45 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*new_str;
	int		len;

	len = ft_strlen(src);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, src, len + 1);
	return (new_str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctr;

	ctr = 0;
	while (src[ctr] && ctr < size - 1 && size > 0)
	{
		dest[ctr] = src[ctr];
		ctr++;
	}
	if (ctr != 0 || !src[ctr])
		dest[ctr] = '\0';
	while (src[ctr])
		ctr++;
	return (ctr);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)str + i) = 0;
		i++;
	}
}