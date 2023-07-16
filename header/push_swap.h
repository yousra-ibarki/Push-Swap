/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:47 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 22:59:39 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 10

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*link;
	int				rank;
}					t_node;

struct s_node		*push_a_bonus(struct s_node **src, struct s_node **dst);
struct s_node		*push_b_bonus(struct s_node **src, struct s_node **dst);
struct s_node		*rra_bonus(struct s_node **stack);
struct s_node		*rrb_bonus(struct s_node **stack);
struct s_node		*ra_bonus(struct s_node **stack);
struct s_node		*rb_bonus(struct s_node **stack);
struct s_node		*sa_bonus(struct s_node *stack);
struct s_node		*sb_bonus(struct s_node *stack);
struct s_node		*sb(struct s_node *stack);
struct s_node		*ra(struct s_node **stack);
struct s_node		*rra(struct s_node **stack);
struct s_node		*sa(struct s_node *stack);
struct s_node		*ft_delete_last_node(struct s_node *head);
struct s_node		*ft_delete_first_node(struct s_node *head);
struct s_node		*ft_add_node(int data, int index);
struct s_node		*ft_add_end(struct s_node *head, int data, int index);
struct s_node		*ft_add_front(struct s_node **head, int data, int index);
struct s_node		*ft_add_end(struct s_node *head, int data, int index);
struct s_node		*ft_add_node(int data, int index);
struct s_node		*ft_fill(char **av);
struct s_node		*rb(struct s_node **stack);
struct s_node		*ft_fill_bonus(int ac, char **av);
struct s_node		*rrb(struct s_node **stack);
struct s_node		*push_b(struct s_node **src, struct s_node **dst);
struct s_node		*push_a(struct s_node **src, struct s_node **dst);
void				ss_bonus(struct s_node *stack_a, struct s_node *stack_b);
void				rr_bonus(struct s_node *stack_a, struct s_node *stack_b);
void				rrr_bonus(struct s_node *stack_a, struct s_node *stack_b);
void				rr(struct s_node *stack_a, struct s_node *stack_b);
void				rrr(struct s_node *stack_a, struct s_node *stack_b);
void				ss(struct s_node *stack_a, struct s_node *stack_b);
size_t				ft_strlen(char *s);
char				*ft_str_join(int size, char **strs, char *sep);
char				**ft_split(char *s, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					ft_count(struct s_node *head);
int					ft_find_max(struct s_node *stack_a);
int					ft_atoi(const char *str);
int					ft_find_min(struct s_node *stack_a);
int					ft_count(struct s_node *head);
int					ft_isdigit_space_minus_plus(int c);
void				ss(struct s_node *stack_a, struct s_node *stack_b);
void				ft_error(void);
void				ft_other_number(struct s_node **stack_a,
						struct s_node **stack_b);
void				ft_three_number(struct s_node **stack_a);
void				ft_five_number(struct s_node **stack_a,
						struct s_node **stack_b);
void				ft_index(struct s_node *stack_t, struct s_node **stack_a);
void				ft_selectionsort(struct s_node **stack_t);
void				ft_cases(struct s_node **stack_a, int time, int i);
void				ft_check(char *str, int ac);
char				*ft_backslash(char *hold);
char				*get_next_line(int fd);
char				*ft_strdup(char *s1);
void				ft_free(struct s_node **stack_a);
void				rr(struct s_node *stack_a, struct s_node *stack_b);
void				rrr(struct s_node *stack_a, struct s_node *stack_b);
void				ft_free(struct s_node **stack);
int					ft_check_sorted(int ac, char **splited);
int					ft_check_sorted_bonus(struct s_node **stack_a,
						struct s_node **stack_b);
char				*ft_strjoin_bonus(char *s1, char *s2);
void				ft_free_splited(char **splited, int j);

#endif