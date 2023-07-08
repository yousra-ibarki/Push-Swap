#include "../push_swap.h"

void ft_free(struct s_node *stack_a)
{
    struct s_node *tmp;
    if (stack_a)
    {
        while (stack_a)
        {
            tmp = stack_a;
            free(tmp);
            stack_a = stack_a->link;
        }
    }
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

static int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void ft_str_cmp(char *str, struct s_node **stack_a, struct s_node **stack_b)
{
    if (ft_strcmp(str, "sa\n") == 0)
        sa(*stack_a);
    else if (ft_strcmp(str, "sb\n") == 0)
        sa(*stack_b);
    else if (ft_strcmp(str, "ss\n") == 0)
        ss(*stack_a, *stack_b);
    else if (ft_strcmp(str, "ra\n") == 0)
        ra(&(*stack_a));
    else if (ft_strcmp(str, "rb\n") == 0)
        ra(&(*stack_b));
    else if (ft_strcmp(str, "rr\n") == 0)
        rr(*stack_a, *stack_b);
    else if (ft_strcmp(str, "rra\n") == 0)
        rra(stack_a);
    else if (ft_strcmp(str, "rrb\n") == 0)
        rra(stack_b);
    else if (ft_strcmp(str, "rrr\n") == 0)
        rrr(*stack_a, *stack_b);
    else if (ft_strcmp(str, "pa\n") == 0)
        push(stack_b, stack_a);
    else if (ft_strcmp(str, "pb\n") == 0)
        push(stack_a, stack_b);
    else
        return (ft_free(*stack_a), ft_error());
    free(str);
}

int ft_check_sorted(struct s_node **stack_a, struct s_node **stack_b)
{
    int count = 0;
    // int len = ft_count(*stack_a);
    while (*stack_a && (*stack_a)->link && (*stack_a)->data < (*stack_a)->link->data)
    {
        if ((*stack_a)->data < (*stack_a)->link->data)
            count++;
        else
            return 0;
        *stack_a = (*stack_a)->link;
    }
    if(*stack_b != NULL)
        return 0;
    return 1;
    // printf("count = %d\tlen = %d\n", count, len);
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
        while (1)
        {
            str = get_next_line(0);
            if (!str || !*str)
                break;
            if (ft_strcmp(str, "\n") == 0)
                break;
            ft_str_cmp(str, &stack_a, &stack_b);
        }
        ft_print_data(stack_a);
        if (ft_check_sorted(&stack_a, &stack_b) == 1)
            write(1, "OK\n", 4);
        else
            write(1, "ko\n", 4);
        if(stack_b)
            ft_free(stack_b);
        ft_free(stack_a);   
    }
    else
        return (0);
}