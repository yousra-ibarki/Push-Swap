NAME =	push_swap
SRCS =	ft_actions.c \
		ft_add_fct.c \
		ft_push_swap.c
		
OBJS = $(SRCS:%.c=%.o)
CC=cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

all: $(NAME)

$(NAME):$(OBJS) libft.h
	$(AR) $(NAME) $(OBJS)

%.o: %.c push_swap.g 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all