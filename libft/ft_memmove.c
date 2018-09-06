/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:41:08 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 15:46:45 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (ptr2 < ptr1)
		while (++i <= len)
			ptr1[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
			*(ptr1++) = *(ptr2++);
	return (dst);
}
