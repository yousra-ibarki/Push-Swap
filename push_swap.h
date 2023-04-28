#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *link;
};

int ft_check_arg(char *str);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif
