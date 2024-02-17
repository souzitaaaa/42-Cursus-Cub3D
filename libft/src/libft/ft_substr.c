/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:08:46 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/27 18:13:53 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*string;
	size_t	a;

	a = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen((char *)str))
	{
		return (ft_strdup(""));
	}
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (str[a] != '\0' && len > 0)
	{
		string[a++] = str[start++];
		len--;
	}
	string[a] = '\0';
	return (string);
}
/*
int	main(void)
{
	char	*teste = "Hori Kyouko";
	int	start;
	char	*p;

	start = 3;
	printf("Original:\n");
	printf("%s\n", teste);
	printf("By the function:\n");
	p = ft_substr(teste, start, 4);
	printf("%s", p);
}
*/
