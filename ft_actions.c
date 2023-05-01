#include "push_swap.h"

//Swap the first 2 elements at the top of the stack,
//DO NOTHING if there is only one or no elements
struct node	*ft_sa(struct node *stack)
{
	int	tmp;

	if (!stack || !stack->link)
		return (0);
	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}
void	ft_ss(struct node *stack_a, struct node *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

//Shift up all elements of stack a by 1

struct node *ra(struct node **stack)
{
	struct node *new_node;

	// if(*stack == NULL)
	// 	return;
	new_node = ft_add_end(*stack, (*stack)->data);
	*stack = delete_node(*stack);
	return *stack;

}
struct node	*rr(struct node *stack_a, struct node *stack_b) //ra and tb rb at the same time
{
	ra(&stack_a);
	ra(&stack_b);
}

// struct node	*rra(struct node *head) //shift down all element of stack a by 1
// {
// }

// struct node	*rrb(struct node *head) //shift down ...... stack b ....
// {
// }

// struct node	*rrr(struct node *head) //rra and rrb at the same time
// {
// }

// struct node	*pa(struct node *head)
// //take the first element at the top of b and put it at the top of a
// {
// }

// struct node	*pb(struct node *head) //take ...... of a ....... of b
// {
// }
int	main(void)
{
	struct node *stacka;
	sa(stacka);
}