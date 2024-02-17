/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:39:24 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/16 15:13:21 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	counter(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i - 1] != c)
			words++;
	}
	return (words);
}

static int	get_word(const char *str, int *end, char c)
{
	size_t	start;

	start = *end;
	while (str[*end] != c && str[*end])
		*end += 1;
	return (*end - start);
}

char	**ft_split(char const *str, char c)
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
	words = counter(str, c);
	out = malloc((words + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	while (i < words)
	{
		while (str[start] == c && str[start])
			start++;
		end = start;
		out[i] = ft_substr(str, end, get_word(str, &start, c));
		i++;
	}
	out[i] = NULL;
	return (out);
}
/*
int	main(void)
{
	char	*teste = "   $USER   $PWD  ";
	char	*c = "$";
	char	**p;

	printf("Original:\n");
	printf("%s\n", teste);
	printf("Prints made during the function:\n");
	p = ft_split(teste, *c, true);
	printf("By the function:\n");
	print_arr(p);
}
-*/
