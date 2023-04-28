#include "push_swap.h"

struct node *ft_add_node(int data)
{
    struct node *add_node = (struct node *)malloc(sizeof(struct node));
    if(!add_node)
        return NULL;
    add_node->data = data;
    add_node->link = NULL;
    return add_node;
}

struct node *ft_add_end(struct node *head, int data)
{
    struct node *add_node = ft_add_node(data);

    if(add_node ==  NULL)
        return head;
    if(head == NULL)
        head = add_node;
    else
    {
        struct node *tmp = head;
        while(tmp->link != NULL)
            {
                tmp =  tmp->link;
            }
        tmp->link = add_node;
    }
    return head;
}

void ft_print_data(struct node *head)
{
    int i = 1;
    if (head == NULL)
        printf("there is no node\n");
    struct node *current = head;

    while (current != NULL)
    {
        printf(" node number %d = %d ->", i, current->data);
        current = current->link;
        i++;
    }
    printf(" NULL\n");
}

int main(int ac, char **av)
{
    int i = 1;
    int nbr;
    struct node *stack_a;
    struct node *stack_b;
    int size;
    struct node *head = NULL;
    stack_b = NULL;
    if (ac > 2)
    {
        stack_a = ft_fill(ac, av);
            while (i < ac)
            {
                nbr = ft_atoi(av[i]);
                head = ft_add_end(head, nbr);
                i++;
            }
        ft_print_data(head);
    }
    else
        return 0;
}
