/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:19:06 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	search;

	search = c;
	while (*str != search)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
/*
int	main(void)
{
	char	teste[] = "Yuzuki Eba";

	printf("Original:\n");
	printf("%s\n", teste);
	printf("By my function:\n");
	printf("%s\n", ft_strchr(teste, 'z'));
	printf("By the original:\n");
	printf("%s\n", strchr(teste, 'z'));
}
*/
