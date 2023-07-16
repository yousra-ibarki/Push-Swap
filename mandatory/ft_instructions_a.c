/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:11:53 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/15 17:11:59 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*sa(struct s_node *stack)
{
	int	tmp;

	write(1, "sa\n", 3);
	if (!stack || !stack->link)
		return (0);
	tmp = stack->data;
	stack->data = stack->link->data;
	stack->link->data = tmp;
	return (stack);
}

void	ss(struct s_node *stack_a, struct s_node *stack_b)
{
	write(1, "ss\n", 3);
	sa(stack_a);
	sb(stack_b);
}

struct s_node	*ra(struct s_node **stack)
{
	struct s_node	*new_node;

	write(1, "ra\n", 3);
	if (!*stack || !(*stack)->link)
		return (0);
	new_node = ft_add_end(*stack, (*stack)->data, (*stack)->index);
	*stack = ft_delete_first_node(*stack);
	return (*stack);
}

struct s_node	*rra(struct s_node **stack)
{
	struct s_node	*new_node;
	struct s_node	*tmp;

	write(1, "rra\n", 4);
	if (!*stack || !(*stack)->link)
		return (0);
	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	new_node = ft_add_front(stack, tmp->data, tmp->index);
	ft_delete_last_node(*stack);
	return (*stack);
}

struct s_node	*push_a(struct s_node **src, struct s_node **dst)
{
	struct s_node	*add_node;

	write(1, "pa\n", 3);
	add_node = ft_add_front(dst, (*src)->data, (*src)->index);
	*src = ft_delete_first_node(*src);
	return (*src);
}
