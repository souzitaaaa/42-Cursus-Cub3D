/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:43:51 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}
/*
int	main(void)
{
	int	stdin;
	int	stdout;
	int	stderr;

	stdin = 0;
	stdout = 1;
	stderr = 2;
	printf("With the standard input:\n");
	ft_putnbr_fd(-45727, stdin);
	printf("\n");
	printf("With the standard output:\n");
	ft_putnbr_fd(-45727, stdout);
	printf("\n");
	printf("With the standard error:\n");
	ft_putnbr_fd(-45727, stderr);
	printf("\n");
}
*/
