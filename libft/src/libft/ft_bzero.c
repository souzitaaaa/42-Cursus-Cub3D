/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:41:40 by dinoguei          #+#    #+#             */
/*   Updated: 2023/09/05 22:26:20 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	char	teste[] = "Mai Sakurajima";
	char	testecpy[] = "Mai Sakurajima";

	printf("Original:\n");
	printf("%s\n", teste);
	printf("By my function:\n");
	ft_bzero(teste, 4);
	printf("%s\n", teste);
	printf("By the original:\n");
	bzero(testecpy, 4);
	printf("%s\n", testecpy);
}
*/
