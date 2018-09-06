/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:44:21 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/24 16:18:42 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && len < maxlen)
		len++;
	return (len);
}
