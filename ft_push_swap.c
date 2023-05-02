/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:07 by yoibarki          #+#    #+#             */
/*   Updated: 2023/05/02 13:40:08 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

struct node	*ft_delete_first_node(struct node *head)
{
	struct node	*tmp;

	tmp = head;
	head = head->link;
	free(tmp);
	return (head);
}

struct node	*ft_delete_last_node(struct node *head)
{
	struct node	*second_last;

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

void	ft_print_data(struct node *head)
{
	int			i;
	struct node	*current;

	i = 1;
	if (head == NULL)
	{
		printf("there is no node\n");
		return ;
	}
	current = head;
	while (current != NULL)
	{
		printf("%d\t", current->data);
		current = current->link;
		i++;
	}
	printf(" NULL\n");
}

struct node	*ft_add_node(int data)
{
	struct node	*add_node;

	add_node = (struct node *)malloc(sizeof(struct node));
	if (!add_node)
		return (NULL);
	add_node->data = data;
	add_node->link = NULL;
	return (add_node);
}

struct node	*ft_add_front(struct node **head, int data)
{
	struct node	*add_node;

	add_node = ft_add_node(data);
	if (add_node == NULL)
		return (*head);
	if (*head == NULL)
		*head = add_node;
	else
	{
		add_node->link = *head;
		*head = add_node;
	}
	//ft_print_data(head);
	return (*head);
}

struct node	*ft_add_end(struct node *head, int data)
{
	struct node	*add_node;
	struct node	*tmp;
	int			i;

	i = 1;
	add_node = ft_add_node(data);
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

struct node	*ft_fill(int ac, char **av)
{
	struct node	*head;
	int			nbr;
	int			i;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		head = ft_add_end(head, nbr);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	struct node	*stack_a;
	struct node	*stack_b;

	stack_b = NULL;
	if (ac > 2)
	{
		stack_a = ft_fill(ac, av);
		ft_print_data(stack_a);
		{
			stack_b = ft_add_node(10);
			stack_b = ft_add_end(stack_b, 12);
			stack_b = ft_add_end(stack_b, 13);
			ft_print_data(stack_b);
		}
	}
	else
		return (0);
}
