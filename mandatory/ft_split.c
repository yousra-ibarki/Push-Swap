/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:24:31 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/15 10:28:27 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countrow(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		return (count + 1);
	else
		return (count);
}

static int	countchar(char const *s, char ch)
{
	int	i;

	i = 0;
	while (*s == ch)
		s++;
	while (*s)
	{
		if (*s != ch)
			i++;
		else
			break ;
		s++;
	}
	return (i);
}

static char	**freethearr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**ss;
	int		row;
	int		j;

	j = -1;
	row = -1;
	if (!s)
		return (0);
	ss = malloc(sizeof(char *) * (countrow(s, c) + 1));
	if (!ss)
		return (0);
	ss[countrow(s, c)] = 0;
	while (s[++row])
	{
		if ((s[row] != c) && (row == 0 || (row > 0 && s[row - 1] == c)))
		{
			ss[++j] = ft_substr(s, row, countchar(s + row, c));
			if (!ss[j])
				return (freethearr(ss));
		}
	}
	return (ss);
}
