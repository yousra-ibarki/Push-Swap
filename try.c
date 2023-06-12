#include "push_swap.h"
void ft_rank(struct s_node *stack_a)
{
	printf("start\n");
	int mindata;
	int pos;
	struct s_node *tmp_stack;
	tmp_stack = stack_a;
	pos = 1;

	mindata = ft_find_min(tmp_stack);
	while(tmp_stack != NULL)
	{
		if(tmp_stack->data == mindata)
		{	stack_a->rank = pos;
			pos++;
			mindata = ft_find_min(tmp_stack);
		}
		tmp_stack = tmp_stack->link;
	}
		
	printf("end\n");

}