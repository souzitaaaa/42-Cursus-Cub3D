/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:36:18 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*temp;
	const char	*temp2;

	temp = dest;
	temp2 = src;
	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (dest);
	}
	while (n > i)
	{
		temp[i] = temp2[i];
		i++;
	}
	return (temp);
}
/*
int	main(void)
{
	char	teste[] = "Yuuki";
	char	teste2[] = "Asuna";
	char	testecpy[] = "Yuuki";

	printf("Originals:\n");
	printf("%s\n", teste);
	printf("%s\n", teste2);
	printf("By my function:\n");
	ft_memcpy(teste, teste2, 3);
	printf("%s\n", teste );
	printf("By the original:\n");
	memcpy(testecpy, teste2, 3);
	printf("%s\n", testecpy );
}
*/
