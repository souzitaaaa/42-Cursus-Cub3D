/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:14:33 by rimarque          #+#    #+#             */
/*   Updated: 2023/11/23 18:37:26 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**arrdup_aux(int len, int *j, char c)
{
	char	**ptr;

	if (c == '\t' || c == ' ')
	{
		ptr = malloc((len + 2) * sizeof(const char *));
		ptr[0] = ft_strdup("\0");
		*j = 1;
	}
	else
	{
		ptr = malloc((len + 1) * sizeof(const char *));
		*j = 0;
	}
	if (!ptr)
		return (NULL);
	return (ptr);
}
