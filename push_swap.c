#include "push_swap.h"

void	ft_print_data(struct node *head)
{
	int			i;
	struct node	*current;

	i = 1;
	if (head == NULL)
		printf("there is no node\n");
	current = head;
	while (current != NULL)
	{
		printf(" node number %d = %d ->", i, current->data);
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

struct node	*ft_add_end(struct node *head, int data)
{
	struct node	*add_node;
	struct node	*tmp;

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

	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		head = ft_add_end(head, nbr);
		i++;
	}
	return (head);
}

void sa(struct node *stack_a)
{
	int node1;
	int node2;
	node1 = stack_a->data;
	stack_a = stack_a->link->link;
	//stack_a->link = stack_a;
	node2 = stack_a->data;

	printf("%d %d\n", node1, node2);
}

int	main(int ac, char **av)
{
	int			i;
	int			nbr;
	int			size;
	struct node	*stack_a;
	struct node	*stack_b;
	int a = 0;
	//struct node	*head;


	i = 1;
	//head = NULL;
	if (ac > 2)
	{
		stack_a = ft_fill(ac, av);
		ft_print_data(stack_a);
		sa(stack_a);
	}
	else
		return (0);
}
