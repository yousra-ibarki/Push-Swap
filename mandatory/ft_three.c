/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:18:38 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/15 10:20:32 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(struct s_node *stack_a)
{
	int				max;
	struct s_node	*current;

	max = stack_a->data;
	current = stack_a->link;
	while (current != NULL)
	{
		if (current->data > max)
			max = current->data;
		current = current->link;
	}
	return (max);
}

int	ft_find_min(struct s_node *stack_a)
{
	int				min;
	struct s_node	*current;

	min = stack_a->data;
	current = stack_a->link;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			(stack_a->rank)++;
		}
		current = current->link;
	}
	return (min);
}

void	ft_three_number(struct s_node **stack_a)
{
	if ((*stack_a)->data == ft_find_min(*stack_a)
		&& (*stack_a)->link->data != ft_find_max(*stack_a))
		return ;
	else if ((*stack_a)->link->link->data == ft_find_max(*stack_a))
		sa((*stack_a));
	else if ((*stack_a)->data == ft_find_max(*stack_a)
		&& (*stack_a)->link->data == ft_find_min(*stack_a))
		ra(&(*stack_a));
	else if ((*stack_a)->data == ft_find_max(*stack_a))
	{
		sa((*stack_a));
		rra(&(*stack_a));
	}
	else if ((*stack_a)->data == ft_find_min(*stack_a))
	{
		sa((*stack_a));
		ra(&(*stack_a));
	}
	else if ((*stack_a)->link->data == ft_find_max(*stack_a))
		rra(&(*stack_a));
}
