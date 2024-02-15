/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:58:01 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		i;
	char	*out;

	i = 0;
	if (!str || !f)
		return (NULL);
	out = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		out[i] = f(i, str[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
