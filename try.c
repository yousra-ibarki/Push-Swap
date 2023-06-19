#include "push_swap.h"


int index_max = (ft_count(*stack_b) - 1);
int pos;
struct s_node *current;
while (*stack_b != NULL)
{
	pos = 0;
	current = *stack_b;
	while (current->index == index_max)
	{
		pos++;
	}

}	