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
} t_node;

int ft_atoi(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void ss(struct s_node *stack_a, struct s_node *stack_b);
struct s_node *ra(struct s_node **stack_a);
struct s_node *sa(struct s_node *stack_a);
struct s_node *rra(struct s_node **stack);
struct s_node *push(struct s_node **src, struct s_node **dst);
struct s_node *ft_fill(int ac, char **av);
struct s_node *ft_delete_last_node(struct s_node *head);
struct s_node *ft_delete_first_node(struct s_node *head);
struct s_node *ft_add_node(int data, int index);
struct s_node *ft_add_end(struct s_node *head, int data, int index);
struct s_node *ft_add_front(struct s_node **head, int data, int index);
struct s_node *ft_add_end(struct s_node *head, int data, int index);
int ft_find_max(struct s_node *stack_a);
int ft_find_min(struct s_node *stack_a);
int	ft_count(struct s_node *head);
void ft_other_number(struct s_node **stack_a, struct s_node **stack_b);
void ft_three_number(struct s_node **stack_a);
void ft_five_number(struct s_node **stack_a, struct s_node **stack_b);
void ft_print_data(struct s_node *head);
struct s_node *ft_add_node(int data, int index);
int	ft_count(struct s_node *head);
void ft_index(struct s_node *stack_t, struct s_node **stack_a);
void ft_selectionSort(struct s_node **stack_t);
void ft_cases(struct s_node **stack_a, int time, int i);
char *ft_strjoin(int size, char **strs, char *sep);
size_t ft_strlen(char *s);
void ft_check(char *str, int ac);
char **ft_split(char *s, char c);
char *ft_substr(char *s, unsigned int start, size_t len);

#endif