/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:49:11 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/06 12:51:09 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_delim(const char *str, char delim)
{
	int 		i;

	i = 0;
	if (str[i] == delim)
	{
		while ((str[i] == delim) && str[i])
		{
			i += 1;
		}
	}
	return (i);
}

static int	ft_count_words_delim(const char *str, char delim)
{
	int			i;
	int 		count;
	int			len;

	i = skip_delim(str, delim);
	count = 0;
	if (str[i] != '\0')
		count += 1;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == delim || str[i] == '\0')
		{
			while ((str[i] == delim) && str[i] != '\0')
				i += 1;
			if (str[i] != '\0')
				count += 1;
		}
		else
			i += 1;
	}
	return (count);
}

char		**ft_strsplit(const char *str, char delim)
{
	int			i;
	char		**strings;
	int			begin;
	int			strings_ptr;
	int			word_count;

	i = 0;
	word_count = ft_count_words_delim(str, delim);
	strings = malloc(sizeof(strings) * (word_count + 1));
	strings_ptr = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delim)
		{
			begin = i;
			while (str[i] != delim  && str[i] != '\0')
				i += 1;
			strings[strings_ptr] = ft_strdup_range((char*)str, begin, i - 1);
			strings_ptr += 1;
		}
		else
			i += 1;
	}
	return (strings);
}
