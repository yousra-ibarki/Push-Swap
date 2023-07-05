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

static void ft_check_digit(char *str)
{
    int len;
    int i;

    len = ft_strlen(str);
    i = 0;
    while (i < len)
    {
        if (ft_isdigit_space(str[i]) == 0)
            ft_error();
        i++;
    }
}

void ft_check(char *str, int ac)
{
    int i;
    char **splited;
    char *tmp;
    int j;

    j = 0;
    splited = ft_split(str, ' ');
    ft_check_digit(str);
    while (j < ac)
    {
        tmp = splited[j];
        i = j + 1;
        while (splited[i] != NULL && tmp != NULL)
        {
            if (ft_strcmp(tmp, splited[i]) == 0)
                {
                    printf("dub\n");
                    ft_error();
                }
            i++;
        }
        j++;
    }
}