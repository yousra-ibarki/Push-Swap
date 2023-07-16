/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_bonus_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:58:08 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 21:59:44 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*sb_bonus(struct s_node *stack)
{
	int	tmp;

	if (!stack || !stack->link)
		return (0);
	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}

struct s_node	*rb_bonus(struct s_node **stack)
{
	struct s_node	*new_node;

	if (!*stack || !(*stack)->link)
		return (0);
	new_node = ft_add_end(*stack, (*stack)->data, (*stack)->index);
	*stack = ft_delete_first_node(*stack);
	return (*stack);
}

void	rr_bonus(struct s_node *stack_a, struct s_node *stack_b)
{
	ra(&stack_a);
	rb(&stack_b);
}

struct s_node	*rrb_bonus(struct s_node **stack)
{
	struct s_node	*new_node;
	struct s_node	*tmp;

	if (!*stack || !(*stack)->link)
		return (0);
	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	new_node = ft_add_front(stack, tmp->data, tmp->index);
	ft_delete_last_node(*stack);
	return (*stack);
}

void	rrr_bonus(struct s_node *stack_a, struct s_node *stack_b)
{
	rra(&stack_a);
	rrb(&stack_b);
}
