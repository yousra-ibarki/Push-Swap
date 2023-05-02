#include "push_swap.h"

//Swap the first 2 elements at the top of the stack,
//DO NOTHING if there is only one or no elements
struct node	*sa(struct node *stack)
{
	int	tmp;

	if (!stack || !stack->link)
		return (0);
	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}
void	ss(struct node *stack_a, struct node *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

//Shift up all elements of stack a by 1
struct node	*ra(struct node **stack)
{
	struct node	*new_node;

	// if(*stack == NULL)
	// 	return ;
	new_node = ft_add_end(*stack, (*stack)->data);
	*stack = ft_delete_first_node(*stack);
	return (*stack);
}
struct node	*rr(struct node *stack_a, struct node *stack_b)
{
	ra(&stack_a);
	ra(&stack_b);
}

//Shift down all elements of the stack by 1
struct node	*rra(struct node **stack)
{
	struct node	*new_node;
	struct node	*tmp;

	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	new_node = ft_add_front(stack, tmp->data);
	ft_delete_last_node(*stack);
	return (*stack);
}
struct node	*rrr(struct node *stack_a, struct node *stack_b)
{
	rra(&stack_a);
	rra(&stack_b);
}

//take the first element at the top of b and put it at the top of a
struct node	*push(struct node **src, struct node **dst)
{
	struct node	*add_node;

	add_node = ft_add_front(dst, (*src)->data);
	*src = ft_delete_first_node(*src);
	return (*src);
}
