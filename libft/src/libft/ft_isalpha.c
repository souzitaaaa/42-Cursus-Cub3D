/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:13:28 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/04 16:17:08 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
		return (0);
}
/*
int	main(void)
{
	int	c;

	c = 'G';
	printf("By my function:\n");
	printf("%d\n", ft_isalpha(c));
	printf("By the original:\n");
	printf("%d\n", isalpha(c));
}
*/
