#include "../push_swap.h"

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

int main(int ac, char **av)
{
	struct s_node *stack_a;
	struct s_node *stack_b;
	char *str;

	stack_b = NULL;
	if (ac > 2)
	{
		stack_a = ft_fill(ac, av);
        str = ft_strjoin(ac, av, " ");
		 ft_check(str, ac);
        while (1)
	{
		str = get_next_line(0);
		if (!str || !*str)
			break;
		ft_str_comp(str)
	}


		ft_print_data(stack_a);
	}
	else
		return (0);
}