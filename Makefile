# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 13:39:57 by yoibarki          #+#    #+#              #
#    Updated: 2023/07/16 08:19:51 by yoibarki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker
HEAD = header

SRCS = 	mandatory/ft_instructions_a.c \
	 	mandatory/ft_instructions_b.c \
		mandatory/ft_atoi.c \
		mandatory/ft_help.c \
		mandatory/ft_three.c \
		mandatory/ft_five.c \
		mandatory/ft_more.c \
		mandatory/ft_strjoin.c \
		mandatory/ft_check.c \
		mandatory/ft_split.c \
		mandatory/ft_substr_strdup.c \
		mandatory/ft_if_sorted.c \
		mandatory/ft_selection_sort.c \
		mandatory/main.c	


BSRCS = bonus/ft_inst_bonus_a.c \
		bonus/ft_inst_bonus_b.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \
 		mandatory/ft_atoi.c \
		mandatory/ft_help.c \
		mandatory/ft_split.c \
		mandatory/ft_strjoin.c \
		mandatory/ft_substr_strdup.c \
		mandatory/ft_check.c \
		mandatory/ft_three.c \
		mandatory/ft_instructions_a.c \
		mandatory/ft_instructions_b.c \
		mandatory/ft_if_sorted.c \
		bonus/ft_checker.c 

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