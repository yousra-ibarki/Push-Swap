#include "push_swap.h"

static char *strrcpy(const char *src, char *dst)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char *ft_strdup(char *s1)
{
    int len;
    char *arr;

    len = ft_strlen(s1);
    arr = malloc(len * sizeof(char) + 1);
    if (arr == NULL)
        return (NULL);
    arr = strrcpy(s1, arr);
    return (arr);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;

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