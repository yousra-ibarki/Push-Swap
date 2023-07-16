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
