#include "push_swap.h"
void ft_error(void)
{
    write(1, "Error\n", 7);
    exit(1);
}

int ft_isdigit_space_minus_plus(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if (c == '-' || c == '+')
        return -1;
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
    if (str[len - 1] == '-' || str[len - 1] == '+')
        ft_error();
    while (i < len)
    {
        if (ft_isdigit_space_minus_plus(str[i]) == 0 && str[i] != ' ')
            ft_error();
        else if ((str[i] == '-' && str[i + 1] == '-') || (str[i] == '+' && str[i + 1] == '+'))
            ft_error();
        if((ft_isdigit_space_minus_plus(str[i]) == -1 && str[i + 1] == ' '))
            ft_error();
        else if((ft_isdigit_space_minus_plus(str[i]) == 1 && ft_isdigit_space_minus_plus(str[i]) == -1))
            ft_error();
        i++;
    }
}

char *ft_remove_plus(char *str)
{
    int i = 0;
    int j = 0;

    while(str[i])
    {
            //printf("str de i = %c && str de i + 1\ = %cn", str[i], str[i + 1]);
        if(str[i] == '+' && ft_isdigit_space_minus_plus(str[i + 1]) == 1)
        {
            j = i;
            while(str[j])
            {
                str[j] = str[j + 1];
                j++;
            }
        }
        i++;
    }
    return str;
}

void ft_check(char *str, int ac)
{
    int i;
    char **splited;
    char *tmp;
    int j;

    j = 0;
    ft_check_digit(str);
    str = ft_remove_plus(str);
    printf("str = %s\n", str);
    splited = ft_split(str, ' ');
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