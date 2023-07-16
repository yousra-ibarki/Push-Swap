/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:23:02 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 18:04:49 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		*s1 = s2[i];
		i++;
		s1++;
	}
	s1[i] = '\0';
	return (s1);
}

static int	ft_len(int size, char **strs, char *sep)
{
	int	i;
	int	len_total;
	int	len_sep;

	len_sep = ft_strlen(sep);
	i = 1;
	len_total = 0;
	while (i < size)
	{
		len_total += len_sep + ft_strlen(strs[i]);
		i++;
	}
	return (len_total - 1);
}

char	*ft_str_join(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	i = 1;
	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	len = ft_len(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < size)
	{
		str = ft_strcpy(str, strs[i]);
		if (i + 1 < size)
			str = ft_strcpy(str, sep);
		i++;
	}
	return (str - len);
}
