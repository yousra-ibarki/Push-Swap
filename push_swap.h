/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:47 by yoibarki          #+#    #+#             */
/*   Updated: 2023/05/02 13:40:51 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

struct			node
{
	int			data;
	int			index;
	struct node	*link;
};

int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ss(struct node *stack_a, struct node *stack_b);
struct node		*ra(struct node **stack_a);
struct node		*sa(struct node *stack_a);
struct node		*ft_fill(int ac, char **av);
struct node		*ft_delete_last_node(struct node *head);
struct node		*ft_delete_first_node(struct node *head);
struct node		*rra(struct node **stack);
struct node		*push(struct node **src, struct node **dst);
struct node		*ft_add_node(int data);
struct node		*ft_add_end(struct node *head, int data);
struct node		*ft_add_front(struct node **head, int data);
struct node		*ft_add_end(struct node *head, int data);

#endif