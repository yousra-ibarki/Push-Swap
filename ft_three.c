#include "push_swap.h"

int ft_find_max(struct s_node *stack_a)
{
	int max;

	max = stack_a->data;
	struct s_node *current = stack_a->link;
	while (current != NULL)
	{
		if (current->data > max)
			max = current->data;
		current = current->link;
	}
	return max;
}

int ft_find_min(struct s_node *stack_a)
{
	int min;

	min = stack_a->data;
	struct s_node *current = stack_a->link;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			(stack_a->rank)++;
		}
		current = current->link;
	}
	return min;
}

struct s_node *sa(struct s_node *stack)
{
	int tmp;

	if (!stack || !stack->link)
		return (0);
	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}

void ss(struct s_node *stack_a, struct s_node *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

void ft_three_number(struct s_node **stack_a)
{
	if ((*stack_a)->data == ft_find_min(*stack_a) && (*stack_a)->link->data != ft_find_max(*stack_a))
		return;
	else if ((*stack_a)->link->link->data == ft_find_max(*stack_a))
	{
		sa((*stack_a));
		write(1, "sa\n", 4);
	}
	else if ((*stack_a)->data == ft_find_max(*stack_a) && (*stack_a)->link->data == ft_find_min(*stack_a))
	{
		ra(&(*stack_a));
		write(1, "ra\n", 4);
	}
	else if ((*stack_a)->data == ft_find_max(*stack_a))
	{
		sa((*stack_a));
		rra(&(*stack_a));
		write(1, "sa\nrra\n", 7);
	}
	else if ((*stack_a)->data == ft_find_min(*stack_a))
	{
		sa((*stack_a));
		ra(&(*stack_a));
		write(1, "sa\nra\n", 7);
	}
	else if ((*stack_a)->link->data == ft_find_max(*stack_a))
	{
		rra(&(*stack_a));
		write(1, "rra\n", 4);
	}
}
