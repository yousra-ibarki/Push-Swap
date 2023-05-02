# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 13:39:57 by yoibarki          #+#    #+#              #
#    Updated: 2023/05/02 13:40:00 by yoibarki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = out

SRCS = 	ft_actions.c \
		ft_add_fct.c \
		ft_push_swap.c

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