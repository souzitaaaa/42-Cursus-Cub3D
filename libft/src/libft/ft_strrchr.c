/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:37:59 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	search;
	char	*out;
	int		strlen;

	out = NULL;
	strlen = ft_strlen((char *)str);
	search = c;
	if (c == '\0')
		return ((char *)str + strlen);
	while (*str)
	{
		if (*str == search)
			out = (char *)str;
		str++;
	}
	return ((char *)out);
}
/*
int	main(void)
{
	char	teste[] = "Momo Deviluke";

	printf("Original:\n");
	printf("%s\n", teste);
	printf("By my function:\n");
	printf("%s\n", ft_strrchr(teste, '\0'));
	printf("By the original:\n");
	printf("%s\n", strrchr(teste, '\0'));
}
*/
