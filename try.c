#include "push_swap.h"

#include <stdio.h>

int ft_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}


int main()
{
    char *str = "";
    char *str2 = "";
    printf("int = %d\n", ft_strcmp(str, str2));
}