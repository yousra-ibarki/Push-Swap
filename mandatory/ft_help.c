/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:13:05 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/15 17:13:08 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*ft_delete_first_node(struct s_node *head)
{
	struct s_node	*tmp;

	tmp = head;
	head = head->link;
	free(tmp);
	return (head);
}

struct s_node	*ft_delete_last_node(struct s_node *head)
{
	struct s_node	*second_last;

	second_last = head;
	if (head == NULL)
		return (NULL);
	if (head->link == NULL)
	{
		free(head);
		return (NULL);
	}
	while (second_last->link->link != NULL)
		second_last = second_last->link;
	free(second_last->link);
	second_last->link = NULL;
	return (head);
}

struct s_node	*ft_add_node(int data, int index)
{
	struct s_node	*add_node;

	add_node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!add_node)
		return (NULL);
	add_node->data = data;
	add_node->index = index;
	add_node->link = NULL;
	return (add_node);
}

struct s_node	*ft_add_front(struct s_node **head, int data, int index)
{
	struct s_node	*add_node;

	add_node = ft_add_node(data, index);
	if (add_node == NULL)
		return (*head);
	if (*head == NULL)
		*head = add_node;
	else
	{
		add_node->link = *head;
		*head = add_node;
	}
	return (*head);
}

struct s_node	*ft_add_end(struct s_node *head, int data, int index)
{
	struct s_node	*add_node;
	struct s_node	*tmp;
	int				i;

	i = 1;
	add_node = ft_add_node(data, index);
	if (add_node == NULL)
		return (head);
	if (head == NULL)
		head = add_node;
	else
	{
		tmp = head;
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
			i++;
		}
		tmp->link = add_node;
	}
	return (head);
}
