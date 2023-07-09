#include "push_swap.h"
char	*ft_backslash(char *hold)
{
	int	i;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i])
	{
		if (hold[i] == '\n')
			return (hold + i);
		i++;
	}
	return (0);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sr;
	int		i;

	i = 0;
	dest = (char *)dst;
	sr = (char *)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		dest[i] = sr[i];
		i++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*ptr;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len1);
	ft_memcpy(ptr + len1, s2, len2);
	ptr[len1 + len2] = '\0';
	free(s1);
	return (ptr);
}
