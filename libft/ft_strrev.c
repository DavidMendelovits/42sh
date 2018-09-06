/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:52:02 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 17:36:37 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		i;
	char	c;

	count = 0;
	while (str[count] != '\0')
		count++;
	count -= 1;
	i = 0;
	while (i < ((count + 1) / 2))
	{
		c = str[i];
		str[i] = str[count - 1];
		str[count - i] = c;
		i++;
	}
	return (str);
}
