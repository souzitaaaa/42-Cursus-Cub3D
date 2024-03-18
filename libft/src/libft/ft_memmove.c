/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:38:32 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	i = n;
	if (temp2 < temp)
	{
		while (i)
		{
			i--;
			temp[i] = temp2[i];
		}
		return (dest);
	}
	ft_memcpy(temp, temp2, n);
	return (dest);
}
/*
int	main(void)
{
	char	teste[] = "Sakura";
	char	teste2[] = "Yamauchi";
	char	testecpy[] = "Sakura";

	printf("Originals:\n");
	printf("%s\n", teste);
	printf("%s\n", teste2);
	printf("By my function:\n");
	ft_memmove(teste, teste2, 3);
	printf("%s\n", teste );
	printf("By the original:\n");
	memmove(testecpy, teste2, 3);
	printf("%s\n", testecpy );
}
*/
