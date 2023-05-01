#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

struct			node
{
	int			data;
	int			index;
	struct node	*link;
};

int				ft_check_arg(char *str);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_ss(struct node *stack_a, struct node *stack_b);
struct node		*ra(struct node **stack_a);
struct node		*ft_sa(struct node *stack_a);
struct node		*ft_add_end(struct node *head, int data);
struct node		*ft_add_node(int data);
struct node		*ft_fill(int ac, char **av);
struct node		*delete_node(struct node *head);

#endif
