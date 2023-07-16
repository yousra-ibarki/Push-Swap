/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:53:25 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 13:27:24 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(struct s_node **stack)
{
	struct s_node	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = *stack;
			free(tmp);
			*stack = (*stack)->link;
		}
	}
}

// int	ft_check_sorted(struct s_node **stack_a, struct s_node **stack_b)
// {
// 	int	count;

// 	count = 0;
// 	while (*stack_a && (*stack_a)->link)
// 	{
// 		ft_print_data(*stack_a);
// 		if ((*stack_a)->data < (*stack_a)->link->data)
// 			{
// 				count++;}
// 		else
// 			return (0);
// 		*stack_a = (*stack_a)->link;
// 	}
// 	if (*stack_b != NULL)
// 		return (0);
// 	return (1);
// }
