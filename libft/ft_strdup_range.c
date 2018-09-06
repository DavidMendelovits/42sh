/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:28:46 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/06 12:30:27 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_range(char *str, int begin, int end)
{
	int			i;
	char		*duplicate;
	int			duplicate_ptr;
	int			range;

	range = end - begin + 1;
	i = begin;
	duplicate = malloc(sizeof(char) * (range + 1));
	duplicate_ptr = 0;
	while (i <= end)
	{
		duplicate[duplicate_ptr] = str[i];
		i += 1;
		duplicate_ptr += 1;
	}
	duplicate[duplicate_ptr] = '\0';
	return (duplicate);
}
