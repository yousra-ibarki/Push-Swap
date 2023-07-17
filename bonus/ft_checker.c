/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:45:00 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/17 14:54:58 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*ft_fill_bonus(int ac, char **av)
{
	struct s_node	*head;
	int				nbr;
	int				i;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		head = ft_add_end(head, nbr, 0);
		i++;
	}
	return (head);
}

static int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

void	ft_str_cmp(char *str, struct s_node **stack_a, struct s_node **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa_bonus(*stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_bonus(*stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss_bonus(*stack_a, *stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra_bonus(&(*stack_a));
	else if (ft_strcmp(str, "rb\n") == 0)
		rb_bonus(&(*stack_b));
	else if (ft_strcmp(str, "rr\n") == 0)
		rr_bonus(*stack_a, *stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra_bonus(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb_bonus(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr_bonus(*stack_a, *stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push_a_bonus(stack_b, stack_a);
	else if (ft_strcmp(str, "pb\n") == 0)
		push_b_bonus(stack_a, stack_b);
	else
		return (ft_error());
}

int	ft_check_sorted_bonus(struct s_node **stack_a, struct s_node **stack_b)
{
	int	count;

	count = 0;
	while (*stack_a && (*stack_a)->link)
	{
		if ((*stack_a)->data < (*stack_a)->link->data)
			count++;
		else
			return (0);
		*stack_a = (*stack_a)->link;
	}
	if (*stack_b != NULL)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	char			*str;

	stack_b = NULL;
	if (ac > 2)
	{
		str = ft_str_join(ac, av, " ");
		ft_check(str, ac);
		stack_a = ft_fill_bonus(ac, av);
		while (1)
		{
			str = get_next_line(0);
			if (!str || !*str)
				break ;
			ft_str_cmp(str, &stack_a, &stack_b);
			free(str);
		}
		if (ft_check_sorted_bonus(&stack_a, &stack_b) == 1)
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
		ft_free(&stack_b);
		ft_free(&stack_a);
	}
}
