/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:12:41 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_printf_arg(const char *print, int i, va_list args)
{
	if (print[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (print[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (print[i + 1] == 'p')
		return (ft_putpointer(va_arg(args, void *), "0123456789abcdef"));
	else if (print[i + 1] == 'd' || print[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (print[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (print[i + 1] == 'x')
		return (ft_puthex(va_arg(args, int), "0123456789abcdef"));
	else if (print[i + 1] == 'X')
		return (ft_puthex(va_arg(args, int), "0123456789ABCDEF"));
	else if (print[i + 1] == '%')
		return (ft_putchar(print[i + 1]));
	else
		return (0);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		i;
	int		out;

	i = 0;
	out = 0;
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%' && ft_strchr("cspdiuxX%", print[i + 1]))
		{
			out += ft_printf_arg(print, i, args);
			i++;
		}
		else
			out += ft_putchar(print[i]);
		i++;
	}
	va_end(args);
	return (out);
}
/*
int main(void)
{
	int c;
	char s[] = "Yor Forger";
	void *p;
	int d;
	int i;
	unsigned int u;
	unsigned int x;
	unsigned int X;
	int z;


	c = 'X';
	p = &s;
	d = 31731;
	i = -9428;
	u = 84274;
	x = 46433;
	X = 46433;
	z = ft_printf("boas\n");
	ft_printf("%d\n", z);
	printf("%d\n",z);
	printf("Printed by my function:\n");
	ft_printf("Char:         %c\n", c);
	ft_printf("String:       %s\n", s);
	ft_printf("Pointer:      %p\n", p);
	ft_printf("Int:          %d\n", d);
	ft_printf("Int:          %i\n", i);
	ft_printf("Unsigned int: %u\n", u);
	ft_printf("Low Hex:      %x\n", x);
	ft_printf("High Hex:     %X\n", X);
	ft_printf("Percentagem:  %%\n");
	ft_printf("Mix: %c next %s proxi %p anda %d ou %u wtf\n", c, s, p, d, u);
	printf("Printed by the original:\n");
	printf("Char:         %c\n", c);
	printf("String:       %s\n", s);
	printf("Pointer:      %p\n", p);
	printf("Int:          %d\n", d);
	printf("Int:          %i\n", i);
	printf("Unsigned int: %u\n", u);
	printf("Low Hex:      %x\n", x);
	printf("High Hex:     %X\n", X);
	printf("Percentagem:  %%\n");
	printf("Mix: %c next %s proxi %p anda %d ou %u wtf\n", c, s, p, d, u);
}
*/
