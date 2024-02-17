/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:14:25 by dinoguei          #+#    #+#             */
/*   Updated: 2023/09/05 22:26:48 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	teste[] = "Tamanna Crusch";
	char	testecpy[] = "Tamanna Crusch";

	printf("Original:\n");
	printf("%s\n", teste);
	printf("By my function:\n");
	ft_memset(teste, 'x', 4);
	printf("%s\n", teste);
	printf("By the original:\n");
	memset(testecpy, 'x', 4);
	printf("%s\n", testecpy);
}
*/
