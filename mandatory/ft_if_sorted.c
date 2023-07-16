/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:53:25 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 15:30:43 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(struct s_node **stack)
{
	struct s_node	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = *stack;
			free(tmp);
			*stack = (*stack)->link;
		}
	}
}

int	ft_check_sorted(int ac, char **splited)
{
	int	j;
	int	i;

	j = 0;
	ac = 0;
	i = j + 1;
	while (splited[j] && splited[i])
	{
		if (ft_atoi(splited[j]) > ft_atoi(splited[i]))
			return (0);
		j++;
		i++;
	}
	return (1);
}
