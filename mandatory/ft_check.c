/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:03:31 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 14:58:50 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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

char	*ft_remove_plus_zero(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '+' && ft_isdigit_space_minus_plus(str[i + 1]) == 1)
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
		}
		i++;
	}
	return (str);
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

void	ft_check(char *str, int ac)
{
	int		i;
	char	**splited;
	char	*tmp;
	int		j;

	j = 0;
	ft_check_digit(str);
	str = ft_remove_plus_zero(str);
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
	i = -1;
	if (ft_check_sorted(ac, splited) != 0)
		exit(1);
	while (++i < j)
		free(splited[i]);
	free(splited);
}
