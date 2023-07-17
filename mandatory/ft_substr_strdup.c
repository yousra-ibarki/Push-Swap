/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:21:20 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/17 11:58:54 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*push_b_bonus(struct s_node **src, struct s_node **dst)
{
	struct s_node	*add_node;

	if (!*src)
		return (0);
	add_node = ft_add_front(dst, (*src)->data, (*src)->index);
	*src = ft_delete_first_node(*src);
	return (*src);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*arr;

	if (!s1)
	{
		arr = malloc(1);
		arr[0] = '\0';
		return (arr);
	}
	len = ft_strlen(s1);
	arr = malloc(len * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	arr = ft_strcpy(arr, s1);
	return (arr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
