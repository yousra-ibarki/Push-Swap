/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:10:53 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 08:16:49 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*sb(struct s_node *stack)
{
	int	tmp;

	write(1, "sb\n", 3);
	if (!stack || !stack->link)
		return (0);
	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}

struct s_node	*rb(struct s_node **stack)
{
	struct s_node	*new_node;

	write(1, "rb\n", 3);
	if (!*stack || !(*stack)->link)
		return (0);
	new_node = ft_add_end(*stack, (*stack)->data, (*stack)->index);
	*stack = ft_delete_first_node(*stack);
	return (*stack);
}

void	rr(struct s_node *stack_a, struct s_node *stack_b)
{
	write(1, "rr\n", 3);
	ra(&stack_a);
	rb(&stack_b);
}

struct s_node	*rrb(struct s_node **stack)
{
	struct s_node	*new_node;
	struct s_node	*tmp;

	write(1, "rrb\n", 4);
	if (!*stack || !(*stack)->link)
		return (0);
	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	new_node = ft_add_front(stack, tmp->data, tmp->index);
	ft_delete_last_node(*stack);
	return (*stack);
}

void	rrr(struct s_node *stack_a, struct s_node *stack_b)
{
	write(1, "rrr\n", 4);
	rra(&stack_a);
	rrb(&stack_b);
}
