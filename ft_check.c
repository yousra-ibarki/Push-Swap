#include "push_swap.h"
void ft_error(void)
{
    write(1, "Error\n", 7);
    exit(1);
}

static int ft_isdigit_space(int c)
{
    if ((c >= '0' && c <= '9') || c == ' ')
        return (1);
    return (0);
}

static int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void ft_check(char *str, int ac)
{
    int i;
    char **splited;
    char *tmp;
    int j;

    j = 0;
    splited = ft_split(str, ' ');
    while (j < ac)
    {
        tmp = splited[j];
        i = j + 1;
        if (ft_isdigit_space(str[i]) == 0)
            ft_error();
        else if (ft_isdigit_space(str[i]) == 1)
        {
            while (splited[i] != NULL && tmp != NULL)
            {
                if (ft_strcmp(tmp, splited[i]) == 0)
                    ft_error();
                i++;
            }
        }
        j++;
    }
}