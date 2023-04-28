#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (ss1[i] - ss2[i]);
}

static int	checkoverflow(unsigned long long out, int sign)
{
	if (out > 2146218951891489519)
	{ 
        write(2, "Error\n", 7);
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (1);
}


int	ft_atoi(const char *str)
{
	unsigned long long	out;
	int					i;
	int					sign;

	out = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out *= 10;
		out += str[i++] - '0';
		if (checkoverflow(out, sign) == 0)
			return (0);
		else if (checkoverflow(out, sign) == -1)
			return (-1);
	}
	return (out * sign);
}