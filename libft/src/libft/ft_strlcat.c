/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:29:20 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/12 14:57:34 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen((char *)src));
	i = 0;
	j = ft_strlen(dest);
	lendest = j;
	lensrc = ft_strlen((char *)src);
	if (size <= lendest)
		return (lensrc + size);
	while (src[i] != '\0' && i < size - lendest - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (lendest + lensrc);
}
