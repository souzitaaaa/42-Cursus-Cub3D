/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:14:45 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 18:02:53 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] > str2[i] || str2[i] > str1[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("Original:\n");
	printf("Shinomiya Kaguya\nFujiwara Chika\nHayasaka Ai\n");
	printf("By my function:\n");
	printf("%d\n", ft_strncmp("Shinomiya Kaguya", "Shinomiya Kaguya", 14));
	printf("%d\n", ft_strncmp("Fujiwura Chika", "Fujiwara Chika", 10));
	printf("%d\n", ft_strncmp("Hayasaka Ai", "Haiasaka Ai", 4));
	printf("By the original:\n");
	printf("%d\n", strncmp("Shinomiya Kaguya", "Shinomiya Kaguya", 14));
	printf("%d\n", strncmp("Fujiwura Chika", "Fujiwara Chika", 10));
	printf("%d\n", strncmp("Hayasaka Ai", "Haiasaka Ai", 4));
}
*/
