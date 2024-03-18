/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:16:57 by rimarque          #+#    #+#             */
/*   Updated: 2023/10/27 17:36:50 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_arrjoin_free(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	**new_s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_arrlen(s1);
	s2_len = ft_arrlen(s2);
	new_s = ft_calloc((s1_len + s2_len + 1), sizeof(char *));
	if (!new_s)
		return (0);
	if (s1_len > 0)
		ft_arrlcpy(new_s, s1, (s1_len + 1));
	free(s1);
	ft_arrlcpy((new_s + s1_len), s2, (s2_len + 1));
	return (new_s);
}

char	**ft_arrjoin(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	**new_s;
	char	*empty_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_arrlen(s1);
	s2_len = ft_arrlen(s2);
	new_s = ft_calloc((s1_len + s2_len + 2), sizeof(char *));
	if (!new_s)
		return (0);
	if (s1_len > 0)
		ft_arrlcpy(new_s, s1, (s1_len + 1));
	empty_str = ft_calloc(1, sizeof(char));
	new_s[s1_len] = empty_str;
	ft_arrlcpy((new_s + s1_len + 1), s2, (s2_len + 2));
	return (new_s);
}

char	**ft_arrjoinfree(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	**new_s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_arrlen(s1);
	s2_len = ft_arrlen(s2);
	new_s = ft_calloc((s1_len + s2_len + 1), sizeof(char *));
	if (!new_s)
		return (0);
	if (s1_len > 0)
	{
		s1[s1_len - 1] = ft_strjoinfree3(s1[s1_len -1], s2[0]);
		ft_arrlcpy(new_s, s1, (s1_len + 1));
	}
	free(s1);
	ft_arrlcpy((new_s + s1_len), s2 + 1, (s2_len));
	return (new_s);
}

char	**ft_arrnl_joinfree(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	**new_s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_arrlen(s1);
	s2_len = ft_arrlen(s2);
	new_s = ft_calloc((s1_len + s2_len + 1), sizeof(char *));
	if (!new_s)
		return (0);
	if (s1_len > 0)
		ft_arrlcpy(new_s, s1, (s1_len + 1));
	free(s1);
	ft_arrlcpy((new_s + s1_len), s2, (s2_len + 1));
	return (new_s);
}

char	**ft_arrnl_strnl_arrjoin(char	**arr1, char	*str, char	**arr2)
{
	size_t	arr1_len;
	size_t	arr2_len;
	char	**new_arr;

	arr1_len = 0;
	arr2_len = 0;
	if (arr1)
		arr1_len = ft_arrlen(arr1);
	if (arr2)
		arr2_len = ft_arrlen(arr2);
	new_arr = ft_calloc((arr1_len + arr2_len + 2), sizeof(char *));
	if (!new_arr)
		return (0);
	if (arr1)
	{
		ft_arrlcpy(new_arr, arr1, (arr1_len + 1));
		if (str)
			new_arr[arr1_len] = str;
	}
	else if (str)
		new_arr[0] = str;
	if (arr2)
		ft_arrlcpy(new_arr + arr1_len + 1, arr2, (arr2_len + 1));
	return (new_arr);
}

/*char	**ft_arrstrjoin(char	**arr, char	*str)
{
	size_t	arr_len;
	char	**new_arr;

	if (!arr || !str)
		return (NULL);
	arr_len = ft_arrlen(arr);
	new_arr = malloc((arr_len + 2) * sizeof(char *));
	if (!new_arr)
		return (0);
	ft_arrlcpy(new_arr, arr, (arr_len + 1));
	new_arr[arr_len] = str;
	return (new_arr);
}

char	**ft_strarrjoin(char *str, char	**arr)
{
	size_t	arr_len;
	char	**new_arr;

	if (!arr || !str)
		return (NULL);
	arr_len = ft_arrlen(arr);
	new_arr = malloc((arr_len + 2) * sizeof(char *));
	if (!new_arr)
		return (0);
	new_arr[0] = str;
	ft_arrlcpy(new_arr + 1, arr, (arr_len + 1));
	return (new_arr);
}*/
