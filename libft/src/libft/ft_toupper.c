/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:46 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	printf("Original:\n");
	printf("%c\n%c\n%c\n", 'a', 'A', '9');
	printf("By my function:\n");
	printf("%c\n%c\n%c\n", ft_toupper('a'), ft_toupper('A'), ft_toupper('9'));
	printf("By the original:\n");
	printf("%c\n%c\n%c\n", toupper('a'), toupper('A'), toupper('9'));
}
*/
