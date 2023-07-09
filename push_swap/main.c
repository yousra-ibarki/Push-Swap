#include "push_swap.h"

struct s_node *ft_fill(int ac, char **av)
{
	struct s_node *head;
	int nbr;
	int i;

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

int ft_count(struct s_node *head)
{
	int i;
	struct s_node *current;

	i = 0;
	if (head == NULL)
	{
		printf("there is no node\n");
		return 0;
	}
	current = head;
	while (current != NULL)
	{
		current = current->link;
		i++;
	}
	return i;
}

void ft_print_data(struct s_node *head)
{
	int i;
	struct s_node *current;

	i = 1;
	if (head == NULL)
		return;
	current = head;
	while (current != NULL)
	{
		printf("data = %d\n", current->data);
		current = current->link;
		i++;
	}
	printf(" NULL\n");
}

void ft_two_number(struct s_node **stack_a)
{
	if ((*stack_a)->data == ft_find_max(*stack_a))
	{
		sa(*stack_a);
		write(1, "sa\n", 4);
	}
	else
		return;
}

int main(int ac, char **av)
{
	struct s_node *stack_a;
	struct s_node *stack_b;
	char *str;

	stack_b = NULL;
	if (ac > 2)
	{
		str = ft_str_join(ac, av, " ");
		 ft_check(str, ac);
		stack_a = ft_fill(ac, av);
		if (ft_count(stack_a) == 2)
			ft_two_number(&stack_a);
		if (ft_count(stack_a) == 3)
			ft_three_number(&stack_a);
		else if (ft_count(stack_a) == 4 || ft_count(stack_a) == 5)
			ft_five_number(&stack_a, &stack_b);
		else if (ft_count(stack_a) > 5)
			ft_other_number(&stack_a, &stack_b);
		ft_print_data(stack_a);

	}
	else
		return (0);
}