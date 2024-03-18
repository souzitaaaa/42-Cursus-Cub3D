/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:55:51 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i++;
	}
}
