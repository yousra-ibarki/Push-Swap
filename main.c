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

int	ft_count(struct s_node *head)
{
	int			i;
	struct s_node	*current;

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

int main(int ac, char **av)
{
	struct s_node *stack_a;
	struct s_node *stack_b;
	char *str;

	stack_b = NULL;
	if (ac > 2)
	{
		stack_a = ft_fill(ac, av);
		str =  ft_strjoin(ac, av, " ");
		ft_check(str, ac);
		if (ft_count(stack_a) == 3)
			ft_three_number(&stack_a);
		else if (ft_count(stack_a) == 4 || ft_count(stack_a) == 5)
			ft_five_number(&stack_a, &stack_b);
		else if (ft_count(stack_a) > 5)
			ft_other_number(&stack_a, &stack_b);

		ft_print_data(stack_a);
		printf("this is the result %s\n", str);
	}
	else
		return (0);
}
