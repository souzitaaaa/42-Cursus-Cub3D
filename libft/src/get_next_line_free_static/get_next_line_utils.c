/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:17:42 by rimarque          #+#    #+#             */
/*   Updated: 2024/04/21 16:21:47 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_free_static.h"

int	count_nl(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count);
}

size_t	gnl_strclen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

void	gnl_strccpy(char *dst, char *src, char c)
{
	size_t	i;

	if (!*src)
		return ;
	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
}

char	*gnl_strjoin(char *line, char **to_read)
{
	char	*dst;
	size_t	len_line;
	size_t	len_read;
	size_t	len_dst;

	len_line = gnl_strclen(line, '\n');
	len_read = gnl_strclen(*to_read, '\n');
	len_dst = len_line + len_read;
	dst = ft_calloc(len_dst + 1, sizeof(char));
	gnl_strccpy(dst, line, '\n');
	gnl_strccpy((dst + len_line), *to_read, '\n');
	if (*line)
		free(line);
	return (dst);
}
