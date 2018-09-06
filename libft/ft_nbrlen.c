#include "libft.h"
int     ft_nbrlen(long long n, int base)
{
    int     len;

    len = 0;
    if (!n)
        return (1);
    while (n)
    {
        n /= base;
        len++;
    }
    return (len);
}
