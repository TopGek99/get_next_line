/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:47:54 by arowe             #+#    #+#             */
/*   Updated: 2021/10/19 11:47:54 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(const char *s1, const char *s2);
int		get_buffer(int fd, char *buf, int buf_size);

#endif