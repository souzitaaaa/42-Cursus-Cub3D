/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:40:15 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/10/26 19:28:06 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	counter(const char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while ((str[i] == 32 || str[i] == 9) && str[i] != '\0')
			i++;
		while (str[i] != 32 && str[i] != 9 && str[i] != '\0')
			i++;
		if (str[i - 1] != 32 || str[i - 1] != 9)
			words++;
	}
	return (words);
}

static int	get_word(const char *str, int *end)
{
	size_t	start;

	start = *end;
	while (str[*end] != 32 && str[*end] != 9 && str[*end])
		*end += 1;
	return (*end - start);
}

char	**ft_split_tab(char const *str)
{
	char	**out;
	int		i;
	int		start;
	int		end;
	int		words;

	i = 0;
	start = 0;
	end = 0;
	if (!str)
		return (NULL);
	words = counter(str);
	out = malloc((words + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	while (i < words)
	{
		while ((str[start] == 32 || str[start] == 9) && str[start])
			start++;
		end = start;
		out[i] = ft_substr(str, end, get_word(str, &start));
		i++;
	}
	out[i] = NULL;
	return (out);
}
