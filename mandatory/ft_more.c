/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:29:11 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/17 14:52:23 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(struct s_node *stack_t, struct s_node **stack_a)
{
	struct s_node	*current;
	int				i;

	current = *stack_a;
	i = 0;
	while (stack_t != NULL)
	{
		i = stack_t->data;
		current = *stack_a;
		while (current != NULL)
		{
			if (current->data == i)
			{
				current->index = stack_t->index;
				break ;
			}
			current = current->link;
		}
		stack_t = stack_t->link;
	}
}

static void	ft_push_to_b(struct s_node **stack_a, struct s_node **stack_b,
		struct s_node *stack_t)
{
	int	i;
	int	j;

	i = 0;
	if (ft_count(*stack_a) <= 100)
		j = 15;
	else if (ft_count(*stack_a) > 100)
		j = 42;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index < i)
		{
			push_b(&(*stack_a), &(*stack_b));
			i++;
		}
		else if ((*stack_a)->index < (i + j))
		{
			push_b(&(*stack_a), &(*stack_b));
			rb(&(*stack_b));
			i++;
		}
		else
			ra(&(*stack_a));
	}
	ft_index(stack_t, &(*stack_b));
}

static void	ft_push_to_a(struct s_node **stack_a, struct s_node **stack_b,
		struct s_node *current, int size)
{
	int	maxi;
	int	pos;

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
				rb(&(*stack_b));
			else if (pos >= size / 2)
				rrb(&(*stack_b));
		}
		push_a(&(*stack_b), &(*stack_a));
		size--;
		maxi--;
	}
}

void	ft_other_number(struct s_node **stack_a, struct s_node **stack_b)
{
	int				content;
	struct s_node	*stack_t;
	struct s_node	*current;
	int				i;

	stack_t = NULL;
	current = *stack_a;
	i = 0;
	while (i < ft_count(*stack_a))
	{
		content = current->data;
		ft_add_front(&stack_t, content, 0);
		current = current->link;
		i++;
	}
	ft_selectionsort(&stack_t);
	ft_index(stack_t, &(*stack_a));
	ft_push_to_b(&(*stack_a), &(*stack_b), stack_t);
	ft_free(&stack_t);
	ft_push_to_a(&(*stack_a), &(*stack_b), current, ft_count(*stack_b));
}
