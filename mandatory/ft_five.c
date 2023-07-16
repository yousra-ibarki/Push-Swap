/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:13:18 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 08:52:10 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_three(struct s_node **stack_a, struct s_node **stack_b)
{
	ft_three_number(&(*stack_a));
	if (ft_count(*stack_b) == 1)
		push_a(&(*stack_b), &(*stack_a));
	else
	{
		push_a(&(*stack_b), &(*stack_a));
		push_a(&(*stack_b), &(*stack_a));
	}
	return ;
}

void	ft_cases(struct s_node **stack_a, int time, int i)
{
	if (i > (ft_count(*stack_a) / 2))
	{
		while (time < (ft_count(*stack_a) - i))
		{
			rra(&(*stack_a));
			time++;
		}
	}
	else if (i <= (ft_count(*stack_a) / 2))
	{
		while (time < i)
		{
			ra(&(*stack_a));
			time++;
		}
	}
}

int	ft_sort_three(struct s_node **stack_a, struct s_node **stack_b, int i)
{
	if (ft_count(*stack_a) == 3)
		ft_call_three(&(*stack_a), &(*stack_b));
	i = 0;
	return (i);
}

void	ft_five_number(struct s_node **stack_a, struct s_node **stack_b)
{
	struct s_node	*current;
	int				i;
	int				j;
	int				time;

	current = *stack_a;
	i = 0;
	j = 0;
	while (j++ < 2)
	{
		while (current != NULL)
		{
			if (ft_find_min(current) == current->data)
			{
				time = 0;
				ft_cases(&(*stack_a), time, i);
				push_b(&(*stack_a), &(*stack_b));
				current = *stack_a;
				i = ft_sort_three(&(*stack_a), &(*stack_b), i);
				break ;
			}
			current = current->link;
			i++;
		}
	}
}
