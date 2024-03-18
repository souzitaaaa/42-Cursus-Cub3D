/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:49:33 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)str;
	while (n)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	teste[] = "Anya Forger";

	printf("Original:\n");
	printf("%s\n", teste);
	printf("By my function:\n");
	printf("%p\n", ft_memchr(teste, 'a', 80));
	printf("By the original:\n");
	printf("%p\n", memchr(teste, 'a', 80));
}
*/
