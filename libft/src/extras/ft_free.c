/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:33:01 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/23 10:33:01 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_str(char **str)
{
	if (*str == NULL)
		return ;
	free(*str);
	*str = NULL;
}

void	ft_free_array(char	***array)
{
	int	i;

	if (*array == NULL)
		return ;
	i = 0;
	while (array[0][i])
	{
		free(array[0][i]);
		array[0][i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

void	ft_free_matrix(char	****matrix)
{
	int	i;

	if (*matrix == NULL)
		return ;
	i = 0;
	while (matrix[0][i])
	{
		ft_free_array(&matrix[0][i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}
