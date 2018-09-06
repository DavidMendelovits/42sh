/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 21:20:51 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/16 20:09:09 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char const *s1, char c)
{
	char	*ret;
	size_t	i;
	size_t	s1_length;

	if (!s1 || !c)
		return (NULL);
	s1_length = ft_strlen(s1);
	if (!(ret = ft_strnew(s1_length + 1)))
		return (NULL);
	i = -1;
	while (++i < s1_length)
		*(ret + i) = *(s1 + i);
	*(ret + i) = c;
	return (ret);
}
