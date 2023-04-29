#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node2
{
    int data;
    struct node2 link;
};

void ft_print_data(struct node *head)
{
    if (head == NULL)
        printf("there is no node\n");
    struct node *current;
    current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->link;
    }
}

void ft_count_node(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("there is no node\n");
    struct node *current;
    current = head;
    while (current != NULL)
    {
        count++;
        current = current->link;
    }
    printf("Number of nodes is %d\n", count);
}

void ft_set_end(struct node *head, int data)
{
    struct node *tmp, *ptr;

    tmp = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    tmp->data = data;
    tmp->link = NULL;

    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = tmp;
}

void ft_swap(struct node *head)
{
    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp = head;
    head = head->link;
    head->link = tmp;
}


int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 2;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 4;
    current->link = NULL;
    head->link->link->link = current;


    struct node2 *headd2 = (struct node2 *)malloc(sizeof(struct node2));

    ft_set_end(head, 5);
    ft_count_node(head);
    ft_print_data(head);
    ft_swap(head);
    ft_push(head);
}