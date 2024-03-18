/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:52:50 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	size_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*transform_str(unsigned int n, char *base)
{
	int		size;
	char	*hex;

	size = size_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hex);
}

int	ft_puthex(unsigned int n, char *base)
{
	int		len;
	char	*str;

	str = transform_str(n, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}
