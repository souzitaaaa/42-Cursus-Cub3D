/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:30:08 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	int	len;

	if (!str || !set)
		return (NULL);
	while (ft_strchr(set, *str) && *str)
	{
		str++;
	}
	len = ft_strlen((char *)str);
	while (ft_strchr(set, str[len]) && len)
	{
		len--;
	}
	return (ft_substr(str, 0, len + 1));
}
/*
int	main(void)
{
	char	*teste = "	Komi Shouko	";
	char	*teste2 = "\t";

	printf("Originals:\n");
	printf("%s\n", teste);
	printf("%s\n", teste2);
	printf("By my function:\n");
	printf("%s\n", ft_strtrim(teste, teste2));
}
*/
