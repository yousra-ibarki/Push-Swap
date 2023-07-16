#include "push_swap.h"

struct s_node *sa_bonus(struct s_node *stack)
{
	int tmp;

	if (!stack || !stack->link)
		return (0);

	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}

void ss_bonus(struct s_node *stack_a, struct s_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

struct s_node *ra_bonus(struct s_node **stack)
{
	struct s_node *new_node;

	if (!*stack || !(*stack)->link)
		return (0);
	new_node = ft_add_end(*stack, (*stack)->data, (*stack)->index);
	*stack = ft_delete_first_node(*stack);
	return (*stack);
}

struct s_node *rra_bonus(struct s_node **stack)
{
	struct s_node *new_node;
	struct s_node *tmp;

	if (!*stack || !(*stack)->link)
		return (0);
	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	new_node = ft_add_front(stack, tmp->data, tmp->index);
	ft_delete_last_node(*stack);
	return (*stack);
}

struct s_node *push_a_bonus(struct s_node **src, struct s_node **dst)
{
	struct s_node *add_node;

	if (!*src)
		return (0);
	add_node = ft_add_front(dst, (*src)->data, (*src)->index);
	*src = ft_delete_first_node(*src);
	return (*src);
}
