#include "push_swap.h"

struct s_tmp{
	int data;
	struct s_tmp link;
};

struct node	*sa(struct node *stacka) //swap the first two elements of stack a
{
	struct node *head, *tmp;


	tmp = stacka->data;
	stacka = stacka->link;
	stacka->data = tmp;
	printf("hello\n");
	//printf("stack a = %d\n", stacka->data);
	return (stacka);
}

// struct node	*sb(struct node *head) //swap the ...... of stack b
// {
// }

// struct node	*ss(struct node *head) //sa and sb at the same time
// {
// }

// struct node	*ra(struct node *head) //shift up all element of stack a by 1
// {
// }

// struct node	*rb(struct node *head) //shift up ......  stack b ....
// {
// }

// struct node	*rr(struct node *head) //ra and tb rb at the same time
// {
// }

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