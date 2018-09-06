/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:16:28 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 21:21:49 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dup(void const *content, size_t content_size)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	void			*new;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	ptr1 = (unsigned char*)content;
	ptr2 = (unsigned char*)new;
	while (*ptr1)
		*(ptr2++) = *(ptr1++);
	return (new);
}
