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

struct node	*ft_add_end(struct node *head, int data)
{
	struct node	*add_node;
	struct node	*tmp;

	add_node = ft_add_node(data);
	if (add_node == NULL)
	{
		return (head);
	}
	if (head == NULL)
	{
		head = add_node;
	}
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

struct node	*ft_add_front(struct node *head, int data)
{
	struct node	*add_node;

	add_node = ft_add_node(data);
	if (add_node == NULL)
		return (head);
	if (head == NULL)
		head = add_node;
	else
	{
		add_node->link = head;
		head = add_node;
	}
	ft_print_data(head);
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

struct node	*delete_node(struct node *head)
{
	struct node	*tmp;

	tmp = head;
	head = head->link;
	free(tmp);
	return (head);
}

struct node	*rra(struct node **stack_a)
{
	struct node	*new_node;

	new_node = ft_add_end(*stack_a, (*stack_a)->data);
	*stack_a = delete_node(*stack_a);
	return (*stack_a);
}

int	main(int ac, char **av)
{
	int			i;
	int			nbr;
	int			size;
	struct node	*stack_a;
	struct node	*stack_b;

	i = 1;
	if (ac > 2)
	{
		stack_a = ft_fill(ac, av);
		ft_print_data(stack_a);
		stack_a = ft_add_front(stack_a, 4);
		ft_print_data(stack_a);
	}
	else
		return (0);
}
