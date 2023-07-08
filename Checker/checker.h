#ifndef CHECKER_H
#define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int data;
	int index;
	struct s_node *link;
	int rank;
} t_node;

int	ft_atoi(const char *str);


#endif
