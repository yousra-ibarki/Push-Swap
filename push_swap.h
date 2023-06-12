/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:47 by yoibarki          #+#    #+#             */
/*   Updated: 2023/05/02 16:49:48 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_node
{
	int data;
	int index;
	struct s_node *link;
	int rank;
	int max;
	int min;
	int mid;
} t_node;

int ft_atoi(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void ss(struct s_node *stack_a, struct s_node *stack_b);
struct s_node *ra(struct s_node **stack_a);
struct s_node *sa(struct s_node *stack_a);
struct s_node *ft_fill(int ac, char **av);
struct s_node *ft_delete_last_node(struct s_node *head);
struct s_node *ft_delete_first_node(struct s_node *head);
struct s_node *rra(struct s_node **stack);
struct s_node *push(struct s_node **src, struct s_node **dst);
struct s_node *ft_add_node(int data);
struct s_node *ft_add_end(struct s_node *head, int data);
struct s_node *ft_add_front(struct s_node **head, int data);
struct s_node *ft_add_end(struct s_node *head, int data);
int ft_find_max(struct s_node *stack_a);
int ft_find_min(struct s_node *stack_a);
int	ft_count(struct s_node *head);

#endif