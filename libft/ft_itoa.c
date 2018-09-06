/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:59:53 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 21:59:07 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_size(unsigned int num)
{
	unsigned int		size;

	size = 0;
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(long long n)
{
	char				*str;
	unsigned int		nb;
	unsigned int		i;
	unsigned int		size;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	size = (unsigned int)get_num_size(nb);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + '0');
	str[size] = '\0';
	return (str);
}
