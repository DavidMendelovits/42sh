/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:07:33 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 17:50:20 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (!(duplicate = (char*)ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
