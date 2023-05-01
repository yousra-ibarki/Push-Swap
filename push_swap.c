#include "push_swap.h"

struct node	*delete_node(struct node *head)
{
	struct node	*tmp;

	tmp = head;
	head = head->link;
	free(tmp);
	return (head);
}

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
	int i = 1;

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

struct node	*ra(struct node **stack)
{
	struct node	*new_node;

	// if(*stack == NULL)
	// 	return ;
	new_node = ft_add_end(*stack, (*stack)->data);
	*stack = delete_node(*stack);
	return (*stack);
}

int	main(int ac, char **av)
{
	struct node	*stack_a;

	//struct node	*stack_b;
	//stack_b = NULL;
	if (ac > 2)
	{
		stack_a = ft_fill(ac, av);
		 ft_print_data(stack_a);
		 ra(&stack_a);
		 ft_print_data(stack_a);
	}
	else
		return (0);
}
