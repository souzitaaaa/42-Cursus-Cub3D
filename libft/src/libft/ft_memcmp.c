/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:28:57 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *str, const void *str2, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;
	size_t			i;

	temp = (unsigned char *)str;
	temp2 = (unsigned char *)str2;
	i = 0;
	while (n)
	{
		if (temp[i] != temp2[i])
			return ((unsigned char)temp[i] - (unsigned char)temp2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
int main(void)
{
	printf("Original:\n");
	printf("Yukinoshita Yukino\nYuigahama Yui\nIsshiki Iroha\n");
	printf("By my function:\n");
	printf("%d\n", ft_memcmp("Yukinoshita Yukino", "Yukinoshita Yukino", 14));
	printf("%d\n", ft_memcmp("Yuigahama Yui", "Yuiguhama Yui", 10));
	printf("%d\n", ft_memcmp("Isshiki Iroha", "Ischiki Iroha", 4));
	printf("By the original:\n");
	printf("%d\n", memcmp("Yukinoshita Yukino", "Yukinoshita Yukino", 14));
	printf("%d\n", memcmp("Yuigahama Yui", "Yuiguhama Yui", 10));
	printf("%d\n", memcmp("Isshiki Iroha", "Ischiki Iroha", 4));
}
*/
