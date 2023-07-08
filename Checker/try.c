#include "../push_swap.h"

void ft_error(void)
{
    write(1, "Error\n", 7);
    exit(0);
}

struct s_node *ft_add_node(int data, int index)
{
	struct s_node *add_node;

	add_node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!add_node)
		return (NULL);
	add_node->data = data;
	add_node->index = index;
	add_node->link = NULL;
	return (add_node);
}
struct s_node	*ft_add_front(struct s_node **head, int data, int index)
{
	struct s_node	*add_node;

	add_node = ft_add_node(data, index);
	if (add_node == NULL)
		return (*head);
	if (*head == NULL)
		*head = add_node;
	else
	{
		add_node->link = *head;
		*head = add_node;
	}
	return (*head);
}

struct s_node	*ft_delete_last_node(struct s_node *head)
{
	struct s_node	*second_last;

	second_last = head;
	if (head == NULL)
		return (NULL);
	if (head->link == NULL)
	{
		free(head);
		return (NULL);
	}
	while (second_last->link->link != NULL)
		second_last = second_last->link;
	free(second_last->link);
	second_last->link = NULL;
	return (head);
}


struct s_node	*ft_add_end(struct s_node *head, int data, int index)
{
	struct s_node	*add_node;
	struct s_node	*tmp;
	int			i;

	i = 1;
	add_node = ft_add_node(data, index);
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

static int	checkoverflow(unsigned long long out, int sign)
{
	if(out > 2147483647)
            ft_error();
	else if (out > 2146218951891489519)
	{
		write(2, "Error\n", 7);
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	out;

	out = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out *= 10;
		out += str[i++] - '0';
		if (checkoverflow(out, sign) == 0)
			return (0);
		else if (checkoverflow(out, sign) == -1)
			return (-1);
	}
	return (out * sign);
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
struct s_node *rra(struct s_node **stack)
{
	struct s_node *new_node;
	struct s_node *tmp;

	tmp = *stack;
	while (tmp->link != NULL)
		tmp = tmp->link;
	printf("hello rra\n");
	new_node = ft_add_front(stack, tmp->data, tmp->index);
	ft_delete_last_node(*stack);
	return (*stack);
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
        ft_print_data(stack_a);
        rra(&stack_a);
        ft_print_data(stack_a);
    }
    else
        return (0);
}