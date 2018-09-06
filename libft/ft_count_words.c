/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:48:37 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/06 12:50:03 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whitespace(char *str)
{
	int 		i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\t')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
		{
			i += 1;
		}
	}
	return (i);
}

int			ft_count_words(char *str)
{
	int			i;
	int 		count;
	int			len;

	i = skip_whitespace(str);
	count = 0;
	if (str[i] != '\0')
		count += 1;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		{
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
				i += 1;
			if (str[i] != '\0')
				count += 1;
		}
		else
			i += 1;
	}
	return (count);
}
