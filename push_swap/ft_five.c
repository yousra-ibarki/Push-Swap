#include "push_swap.h"

void ft_call_three(struct s_node **stack_a, struct s_node **stack_b)
{
	ft_three_number(&(*stack_a));
	if (ft_count(*stack_b) == 1)
		push(&(*stack_b), &(*stack_a));
	else
	{
		push(&(*stack_b), &(*stack_a));
		push(&(*stack_b), &(*stack_a));
	}
	return;
}

void ft_cases(struct s_node **stack_a, int time, int i)
{
	if (i > (ft_count(*stack_a) / 2))
		while (time < (ft_count(*stack_a) - i))
		{
			rra(&(*stack_a));
			time++;
		}
	else if (i <= (ft_count(*stack_a) / 2))
		while (time < i)
		{
			ra(&(*stack_a));
			time++;
		}
}

void ft_five_number(struct s_node **stack_a, struct s_node **stack_b)
{
	struct s_node *current;
	current = *stack_a;
	int i = 0;
	int time;
	int j = 0;
	time = 0;

	while (j++ < 2)
		while (current != NULL)
		{
			if (ft_find_min(current) == current->data)
			{
				time = 0;
				ft_cases(&(*stack_a), time, i);
				push(&(*stack_a), &(*stack_b));
				current = *stack_a;
				if (ft_count(*stack_a) == 3)
					ft_call_three(&(*stack_a), &(*stack_b));
				i = 0;
				break;
			}
			current = current->link;
			i++;
		}
}