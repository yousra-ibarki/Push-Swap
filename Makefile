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
		ft_libft.c \
		ft_help.c \
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