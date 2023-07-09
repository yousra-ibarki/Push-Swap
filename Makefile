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

NAME = mandatory
BNAME = push_bonus
HEAD = header

SRCS = 	push_swap/ft_instructions.c \
		push_swap/ft_atoi.c \
		push_swap/ft_help.c \
		push_swap/ft_three.c \
		push_swap/ft_five.c \
		push_swap/ft_more.c \
		push_swap/ft_strjoin.c \
		push_swap/ft_check.c \
		push_swap/ft_split.c \
		push_swap/ft_substr_strdup.c \
		push_swap/main.c	

BSRCS = Checker/ft_checker.c \
		push_swap/ft_atoi.c \
		push_swap/ft_help.c \
		push_swap/ft_split.c \
		push_swap/ft_strjoin.c \
		push_swap/ft_substr_strdup.c \
		push_swap/ft_check.c \
		push_swap/ft_instructions.c \
		push_swap/ft_three.c \
		Checker/get_next_line.c \
		Checker/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

bonus: $(NAME) $(BNAME)

$(BNAME) : $(BOBJS) 
	$(CC) $(CFLAGS) $(BOBJS) -o $@

%.o : %.c $(HEAD)/push_swap.h
		$(CC) $(CFLAGS) -c $< -I $(HEAD) -o $@


clean:
	@rm -f $(OBJS) $(BOBJS)

fclean:clean
	@rm -f $(NAME) $(BNAME)

re: fclean all

.phony: re clean fclean all bonus 