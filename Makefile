# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 13:39:57 by yoibarki          #+#    #+#              #
#    Updated: 2023/05/02 13:51:57 by yoibarki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = out

SRCS = 	ft_instructions.c \
		ft_atoi.c \
		ft_help.c \
		ft_three.c \
		ft_five.c \
		ft_more.c \
		ft_strjoin.c \
		ft_check.c \
		ft_split.c \
		ft_substr_strdup.c \
		main.c	

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):$(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.phony: re clean fclean all