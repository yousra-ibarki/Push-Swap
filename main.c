/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:07 by yoibarki          #+#    #+#             */
/*   Updated: 2023/05/02 16:48:12 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void	ft_print_data(struct s_node *head)
{
	int			i;
	struct s_node	*current;

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

struct s_node	*ft_add_node(int data)
{
	struct s_node	*add_node;

	add_node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!add_node)
		return (NULL);
	add_node->data = data;
	add_node->link = NULL;
	return (add_node);
}

struct s_node	*ft_fill(int ac, char **av)
{
	struct s_node	*head;
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
	struct s_node	*stack_a;
	struct s_node	*stack_b;

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
