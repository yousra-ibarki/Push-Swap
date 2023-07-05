#include "push_swap.h"

void ft_selectionSort(struct s_node **stack_t)
{
	struct s_node *current = *stack_t;
	struct s_node *minN;
	int tmp;
	while (current != NULL)
	{
		minN = current;
		struct s_node *temp = current->link;
		while (temp != NULL)
		{
			if (temp->data < minN->data)
			{
				minN = temp;
			}
			(temp->index)++;
			temp = temp->link;
		}
		tmp = current->data;
		current->data = minN->data;
		minN->data = tmp;
		current = current->link;
	}
}

void ft_index(struct s_node *stack_t, struct s_node **stack_a)
{
	struct s_node *current;
	current = *stack_a;
	int i = 0;
	while (stack_t != NULL)
	{
		i = stack_t->data;
		current = *stack_a;
		while (current != NULL)
		{
			if (current->data == i)
			{
				current->index = stack_t->index;
				break;
			}
			current = current->link;
		}
		stack_t = stack_t->link;
	}
}

void ft_push_to_b(struct s_node **stack_a, struct s_node **stack_b, struct s_node *stack_t)
{
	int i;
	int j;
	i = 0;
	if (ft_count(*stack_a) < 100)
		j = 15;
	else if (ft_count(*stack_a) >= 100)
		j = 42;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index > i)
		{
			push(&(*stack_a), &(*stack_b));
			i++;
		}
		else if ((*stack_a)->index <= i && (*stack_a)->index < (i + j))
		{
			push(&(*stack_a), &(*stack_b));
			ra(&(*stack_b));
			i++;
		}
		else
			ra(&(*stack_a));
	}
	ft_index(stack_t, &(*stack_b));
	free(stack_t);
}

void ft_push_to_a(struct s_node **stack_a, struct s_node **stack_b, struct s_node *current)
{
	int maxi;
	int size;
	int pos;

	size = ft_count(*stack_b);
	maxi = (size - 1);
	while (*stack_b != NULL)
	{
		current = *stack_b;
		pos = 0;
		while (current->index != maxi)
		{
			pos++;
			current = current->link;
		}
		while ((*stack_b)->index != maxi)
		{
			if (pos < size / 2)
				ra(&(*stack_b));
			else if (pos >= size / 2)
				rra(&(*stack_b));
		}
		push(&(*stack_b), &(*stack_a));
		size--;
		maxi--;
	}
}

void ft_other_number(struct s_node **stack_a, struct s_node **stack_b)
{
	int content;
	struct s_node *stack_t;
	struct s_node *current;
	stack_t = NULL;
	current = *stack_a;
	int i = 0;

	while (i < ft_count(*stack_a))
	{
		content = current->data;
		ft_add_front(&stack_t, content, 0);
		current = current->link;
		i++;
	}
	ft_selectionSort(&stack_t);
	ft_index(stack_t, &(*stack_a));
	ft_push_to_b(&(*stack_a), &(*stack_b), stack_t);
	ft_push_to_a(&(*stack_a), &(*stack_b), current);
}