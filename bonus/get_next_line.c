/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:58:55 by yoibarki          #+#    #+#             */
/*   Updated: 2023/07/16 21:58:57 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_line(char *hold)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	next_line = malloc(sizeof(char) * (i + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		next_line[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
		next_line[i] = '\n';
	next_line[i] = '\n';
	next_line[i + 1] = '\0';
	return (next_line);
}

char	*ft_nextone(char *hold)
{
	int		i;
	char	*rest;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(hold);
	if (!hold)
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	i++;
	rest = malloc(sizeof(char) * (len - i) + 1);
	if (!rest)
		return (NULL);
	while (hold[i])
		rest[j++] = hold[i++];
	rest[j] = '\0';
	free(hold);
	return (rest);
}

char	*nbb_null(char *buffer_hold, char **hold, char *ret, int nbb)
{
	if (nbb < 0)
		return (free(buffer_hold), NULL);
	else if (nbb == 0)
	{
		free(buffer_hold);
		ret = ft_strdup(*hold);
		if (*hold)
		{
			free(*hold);
			*hold = NULL;
		}
		if (ret[0] == '\0')
			return (free(ret), NULL);
		return (ret);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer_hold;
	int			nbb;
	char		*ret;

	ret = NULL;
	nbb = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer_hold = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer_hold)
		return (NULL);
	while (!ft_backslash(hold) && nbb != 0)
	{
		nbb = read(fd, buffer_hold, BUFFER_SIZE);
		if (nbb <= 0)
			return (nbb_null(buffer_hold, &hold, ret, nbb));
		buffer_hold[nbb] = '\0';
		hold = ft_strjoin_bonus(hold, buffer_hold);
	}
	free(buffer_hold);
	buffer_hold = get_line(hold);
	hold = ft_nextone(hold);
	return (buffer_hold);
}
