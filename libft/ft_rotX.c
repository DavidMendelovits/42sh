#include "libft.h"

char     *ft_rotX(char *str, int x)
{
    int     i;
    char    *cipher;

    i = 0;
    cipher = ft_strdup(str);
    while (cipher[i] != '\0')
    {
        if (ft_isupper(cipher[i]))
            cipher[i] = (((cipher[i] - 'A') + x) % 26) + 'A';
        else if (ft_islower(cipher[i]))
            cipher[i] = (((cipher[i] - 'a') + x) % 26) + 'a';  
        i++;
    }
    return (cipher);
}
