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

void ft_three_number(struct s_node **stack_a)
{
	if((*stack_a)->data == ft_find_min(*stack_a) && (*stack_a)->link->data != ft_find_max(*stack_a))
		return ;
	else if((*stack_a)->link->link->data == ft_find_max(*stack_a))
		{
			printf("sa\n");
			sa((*stack_a));
		}
	else if((*stack_a)->data == ft_find_max(*stack_a) && (*stack_a)->link->data == ft_find_min(*stack_a))
		{
			printf("ra\n");
			ra(&(*stack_a));
		}
	else if((*stack_a)->data == ft_find_max(*stack_a))
	{
		printf("sa rra\n");
		sa((*stack_a));
		rra(&(*stack_a));
	}
	else if((*stack_a)->data == ft_find_min(*stack_a))
	{
		printf("sa ra\n");
		sa((*stack_a));
		ra(&(*stack_a));
	}
	else if((*stack_a)->link->data == ft_find_max(*stack_a))
		{
			printf("rra\n");
			rra(&(*stack_a));
		}
}

void ft_five_number(struct s_node **stack_a, struct s_node **stack_b)
{
	struct s_node *current;
	current = *stack_a;
	int i = 0;
	int time;
	int pos;
	int j = 0;
	time = 0;
	while(j < 2)
	{
		while(current != NULL)
		{
			if(ft_find_min(current) == current->data)
			{
				pos = i;
				i = 0;
				time = 0;
				if(pos > (ft_count(*stack_a)/2))
				{
					while(time < (ft_count(*stack_a) - pos))
					{
						rra(&(*stack_a));
						time++;
					}
					push(&(*stack_a), &(*stack_b));
					current= *stack_a;
				}
				else if(pos <= (ft_count(*stack_a)/2))
				{
					while(time < pos)
					{
						ra(&(*stack_a));
						time++;
					}
					push(&(*stack_a), &(*stack_b));
					current = *stack_a;
				}
				if(ft_count(*stack_a) == 3)
				{
					ft_three_number(&(*stack_a));
					push(&(*stack_b), &(*stack_a));
					push(&(*stack_b), &(*stack_a));
					return ;
				}
				break;	
			}
			current = current->link;
			 i++;
		}
		j++;
	}
}

void ft_selectionSort(struct s_node **stack_t) 
{
    struct s_node *current = *stack_t;
    struct s_node *minN;
	int tmp;
    while (current != NULL) 
	{
        minN = current;
        struct s_node *temp = current->link;
        while (temp != NULL) 
		{
            if (temp->data < minN->data) 
			{
                minN = temp;
            }
            temp = temp->link;
        }
	
	tmp = current->data;
    current->data = minN->data;
    minN->data = tmp;
    current = current->link;
	}
}

void ft_other_number(struct s_node **stack_a, struct s_node **stack_b)
{
	int content;
	struct s_node *stack_t;
	struct s_node *current;
	stack_t = NULL;
	current = *stack_a;
	stack_b = NULL;
	int i = 0;

	while(i < ft_count(*stack_a))
	{
		content = current->data;
		ft_add_front(&stack_t, content);
		current = current->link;
		i++;
	}
	
	ft_selectionSort(&stack_t);
	ft_print_data(stack_t);

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

		stack_a->max = ft_find_max(stack_a);
		stack_a->min = ft_find_min(stack_a);
		//printf("max = %d, min = %d\n", stack_a->max, stack_a->min);

		if(ft_count(stack_a) == 3)
			ft_three_number(&stack_a);

		else if(ft_count(stack_a) == 4 || ft_count(stack_a) == 5)
			ft_five_number(&stack_a, &stack_b);
		else if(ft_count(stack_a) > 5)
			ft_other_number(&stack_a, &stack_b);
		
		//ft_print_data(stack_a);
		//ft_print_data(stack_b);
	}
	else
		return (0);
}
