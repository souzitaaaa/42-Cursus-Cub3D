/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:48:24 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	get_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != '\0')
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		len;

	len = get_len(n);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out[len] = '\0';
	len--;
	if (n < 0)
		out[0] = '-';
	if (n == 0)
		out[0] = '0';
	while (n != '\0')
	{
		out[len] = get_value(n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (out);
}
/*
int		main(void)
{
	int number1 = 123456789;
	int number2 = 1;
	int number3 = 0;
	int number4 = -123456789;
	int number5 = -1;
	int number6 = -0;

	printf("%s\n", ft_itoa(number1));
	printf("%s\n", ft_itoa(number2));
	printf("%s\n", ft_itoa(number3));
	printf("%s\n", ft_itoa(number4));
	printf("%s\n", ft_itoa(number5));
	printf("%s\n", ft_itoa(number6));
}
*/
