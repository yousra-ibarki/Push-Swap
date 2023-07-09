/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:21 by yoibarki          #+#    #+#             */
/*   Updated: 2023/05/02 16:47:55 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node *ra(struct s_node **stack)
{
	struct s_node *new_node;
	
	new_node = ft_add_end(*stack, (*stack)->data, (*stack)->index);
	*stack = ft_delete_first_node(*stack);
	return (*stack);
}

void rr(struct s_node *stack_a, struct s_node *stack_b)
{
	ra(&stack_a);
	ra(&stack_b);
}

struct s_node *rra(struct s_node **stack)
{
	struct s_node *new_node;
	struct s_node *tmp;

	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	printf("hello rra\n");
	new_node = ft_add_front(stack, tmp->data, tmp->index);
	ft_delete_last_node(*stack);
	return (*stack);
}

void rrr(struct s_node *stack_a, struct s_node *stack_b)
{
	rra(&stack_a);
	rra(&stack_b);
}

struct s_node *push(struct s_node **src, struct s_node **dst)
{
	struct s_node *add_node;

	add_node = ft_add_front(dst, (*src)->data, (*src)->index);
	*src = ft_delete_first_node(*src);
	return (*src);
}
