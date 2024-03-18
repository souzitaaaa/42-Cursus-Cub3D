/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:00:03 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/26 19:30:56 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char *str, const char *str2)
{
	char	*temp;
	int		i;
	int		len1;
	int		len2;

	if (!str || !str2)
		return (NULL);
	len1 = ft_strlen((char *)str);
	len2 = ft_strlen ((char *)str2);
	temp = malloc((len1 + len2 + 1) * sizeof(const char));
	if (!temp)
		return (NULL);
	i = 0;
	while (len1 > i)
		temp[i++] = *str++;
	i = 0;
	while (len2 > i)
		temp[len1 + i++] = *str2++;
	temp[len1 + i] = '\0';
	return (temp);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s1, (s1_len + 1));
	ft_strlcpy((new_s + s1_len), s2, (s2_len + 1));
	ft_free_str((char **)&s1);
	return (new_s);
}

char	*ft_strjoinfree2(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s1, (s1_len + 1));
	ft_strlcpy((new_s + s1_len), s2, (s2_len + 1));
	ft_free_str((char **)&s2);
	return (new_s);
}

char	*ft_strjoinfree3(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s1, (s1_len + 1));
	ft_strlcpy((new_s + s1_len), s2, (s2_len + 1));
	ft_free_str((char **)&s1);
	ft_free_str((char **)&s2);
	return (new_s);
}

/*
int	main(void)
{
	char	*teste = "Nanakusa ";
	char	*teste2 = "Nazuna";

	printf("Originals:\n");
	printf("%s\n", teste);
	printf("%s\n", teste2);
	printf("By my function:\n");
	printf("%s\n", ft_strjoin(teste, teste2));
}
*/
