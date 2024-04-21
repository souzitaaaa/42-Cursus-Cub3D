# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 10:28:56 by dinoguei          #+#    #+#              #
#    Updated: 2024/04/21 16:19:41 by dinoguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_len.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_cpy.c \
		libft/ft_strlcat.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_strnstr.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_strdup_utils.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_arrjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \
		ft_printf/ft_printf_hex.c \
		ft_printf/ft_printf_pointer.c \
		get_next_line/get_next_line.c \
		get_next_line_free_static/get_next_line.c \
		get_next_line_free_static/get_next_line_utils.c \
		extras/ft_utoa.c \
		extras/ft_strcmp.c \
		extras/ft_atol.c \
		extras/ft_print.c \
		extras/ft_strtrimall.c \
		extras/ft_free.c \
		extras/ft_split_tab.c \

OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)

SRCDIR = src
OBJSDIR = objs
INCLUDE = include

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(OBJSDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
