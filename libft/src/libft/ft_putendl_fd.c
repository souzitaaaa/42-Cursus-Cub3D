/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:39:22 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	n;

	if (!s)
		return ;
	n = ft_strlen((char *)s);
	write(fd, &*s, n);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char teste[] = "Rias Gremory";
	int	stdin;
	int	stdout;
	int	stderr;

	stdin = 0;
	stdout = 1;
	stderr = 2;
	printf("With the standard input:\n");
	ft_putendl_fd(teste, stdin);
	printf("\n");
	printf("With the standard output:\n");
	ft_putendl_fd(teste, stdout);
	printf("\n");
	printf("With the standard error:\n");
	ft_putendl_fd(teste, stderr);
	printf("\n");
}
*/
