/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:43:29 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/18 15:04:45 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr1;
	char	*ptr2;
	char	*result;

	if (!s || !(result = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	ptr1 = (char*)s;
	ptr2 = result;
	while (*ptr1)
		*(ptr2++) = f(*(ptr1++));
	return (result);
}
