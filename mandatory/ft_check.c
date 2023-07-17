/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:03:31 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/17 14:54:43 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_space_minus_plus(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-' || c == '+')
		return (-1);
	return (0);
}

static void	ft_check_digit(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (str[len - 1] == '-' || str[len - 1] == '+')
		ft_error();
	while (i < len)
	{
		if (ft_isdigit_space_minus_plus(str[i]) == 0 && str[i] != ' ')
			ft_error();
		else if ((str[i] == '-' && str[i + 1] == '-') || (str[i] == '+' && str[i
					+ 1] == '+'))
			ft_error();
		else if ((str[i] == '-' && str[i + 1] == '+'))
			ft_error();
		else if ((ft_isdigit_space_minus_plus(str[i]) == -1 && str[i
					+ 1] == ' '))
			ft_error();
		else if ((ft_isdigit_space_minus_plus(str[i]) == 1
				&& ft_isdigit_space_minus_plus(str[i + 1]) == -1))
			ft_error();
		i++;
	}
}

void	ft_free_splited(char **splited, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

int	ft_check(char *str, int ac)
{
	int		i;
	char	**splited;
	char	*tmp;
	int		j;

	j = 0;
	ft_check_digit(str);
	splited = ft_split(str, ' ');
	while (j < ac)
	{
		tmp = splited[j];
		i = j + 1;
		while (splited[i] != NULL && tmp != NULL)
		{
			if (ft_atoi(splited[i]) == ft_atoi(tmp))
				ft_error();
			i++;
		}
		j++;
	}
	if (ft_check_sorted(ac, splited) != 0)
		return (1);
	ft_free_splited(splited, j);
	free(str);
	return (0);
}
