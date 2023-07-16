/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:20:37 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 08:21:13 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selectionsort(struct s_node **stack_t)
{
	struct s_node	*current;
	struct s_node	*min;
	int				tmp;
	struct s_node	*temp;

	current = *stack_t;
	while (current != NULL)
	{
		min = current;
		temp = current->link;
		while (temp != NULL)
		{
			if (temp->data < min->data)
			{
				min = temp;
			}
			(temp->index)++;
			temp = temp->link;
		}
		tmp = current->data;
		current->data = min->data;
		min->data = tmp;
		current = current->link;
	}
}
