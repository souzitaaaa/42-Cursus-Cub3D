/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:17:05 by dinoguei          #+#    #+#             */
/*   Updated: 2023/11/23 18:31:41 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
/*
Libraries
*/
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "get_next_line.h"

/*
libft
*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str, const void *str2, size_t n);
char	*ft_strnstr(const char *str, const char *substr, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t n, size_t size);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//FT_LEN.C
size_t	ft_strlen(const char *str);
size_t	ft_strclen(char const *s, char c);
size_t	ft_arrlen(char **arr);
//FT_CPY.C
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_arrlcpy(char **dst, char **src, size_t size);
void	ft_strccpy(char *dst, char *src, char c);
//FT_STRJOIN.C
char	*ft_strjoin(char *str, const char *str2);
char	*ft_strjoinfree(char const *s1, char const *s2);
char	*ft_strjoinfree2(char const *s1, char const *s2);
char	*ft_strjoinfree3(char const *s1, char const *s2);
//FT_ARRJOIN.C
char	**ft_arrjoinfree(char **s1, char **s2);
char	**ft_arrjoin_free(char **s1, char **s2);
char	**ft_arrjoin(char **s1, char **s2);
char	**ft_arrnl_joinfree(char **s1, char **s2);
char	**ft_arrnl_strnl_arrjoin(char	**arr1, char	*str, char	**arr2);
//char	**ft_arrstrjoin(char	**arr, char	*str);
//char	**ft_strarrjoin(char *str, char	**arr);
//FT_STRDUP
char	*ft_strdup(const char *str);
char	**ft_arrdup(char **arr);
char	**ft_arrdup_bzero_first(char **arr, char c);
char	**ft_arrdup_bzero_last(char **arr, char c);
char	**ft_arr_bzero(void);
char	**arrdup_aux(int len, int *j, char c);

/*
ft_printf
*/
int		ft_printf(const char *print, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(unsigned int n, char *base);
int		ft_putpointer(void *n, char *base);

/*
extras
*/
char	*ft_utoa(unsigned int n);
int		ft_strcmp(char *s1, char *s2);
long	int	ft_long_atol(const char *str);
char	*ft_strtrimall(char const *str);
//FT_PRINT.C
void	print_arr(char **arr);
void	print_matrix(char ***matrix);
//FT_FREE.C
void	ft_free_str(char **str);
void	ft_free_array(char	***array);
void	ft_free_matrix(char	****matrix);

char	**ft_split_tab(const char *str);

#endif
