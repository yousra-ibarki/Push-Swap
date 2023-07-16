/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:08:54 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 14:56:17 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_data(struct s_node *head)
{
	int				i;
	struct s_node	*current;

	i = 1;
	if (head == NULL)
		return ;
	current = head;
	while (current != NULL)
	{
		printf("data = %d\n", current->data);
		current = current->link;
		i++;
	}
}

struct s_node	*push_b(struct s_node **src, struct s_node **dst)
{
	struct s_node	*add_node;

	write(1, "pb\n", 3);
	add_node = ft_add_front(dst, (*src)->data, (*src)->index);
	*src = ft_delete_first_node(*src);
	return (*src);
}

struct s_node	*ft_fill(int ac, char **av)
{
	struct s_node	*head;
	int				nbr;
	int				i;
	char			**str;
	int				j;

	ac = 0;
	head = NULL;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			ft_error();
		str = ft_split(av[i], ' ');
		j = 0;
		while (str[j])
		{
			nbr = ft_atoi(str[j]);
			head = ft_add_end(head, nbr, 0);
			j++;
		}
		i++;
	}
	return (head);
}

int	ft_count(struct s_node *head)
{
	int				i;
	struct s_node	*current;

	i = 0;
	if (head == NULL)
		return (0);
	current = head;
	while (current != NULL)
	{
		current = current->link;
		i++;
	}
	return (i);
}

void	ft_two_number(struct s_node **stack_a)
{
	if ((*stack_a)->data == ft_find_max(*stack_a))
		sa(*stack_a);
	else
		return ;
}

int	main(int ac, char **av)
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	char			*str;

	stack_b = NULL;
	if (ac >= 2)
	{
		str = ft_str_join(ac, av, " ");
		ft_check(str, ac);
		stack_a = ft_fill(ac, av);
		if (ft_count(stack_a) == 2)
			ft_two_number(&stack_a);
		else if (ft_count(stack_a) == 3)
			ft_three_number(&stack_a);
		else if (ft_count(stack_a) == 4 || ft_count(stack_a) == 5)
			ft_five_number(&stack_a, &stack_b);
		else if (ft_count(stack_a) > 5)
			ft_other_number(&stack_a, &stack_b);
		//ft_print_data(stack_a);
		ft_free(&stack_b);
		ft_free(&stack_a);
	}
	else
		exit(0);
}
