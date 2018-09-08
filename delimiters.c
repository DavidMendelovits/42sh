/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 07:45:05 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/08 09:04:03 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				is_delim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (1);
	}
	return (0);
}

int				is_quote(char c)
{
	if (c == '"' || c == ''')
	{
		return (1);
	}
	return (0);
}

int				is_special_char(char c)
{
	if (c == '!' || c == '{' || c == '}' || c == '"' || c == '\'' ||
		c == ';' || c == '|' || c == '&' || c == '$' || c == '`' ||
		c == ')' || c == ')' || c == '[' || c == ']' )
	{
		return (1);
	}
	return (0);
}

int				skip_delim(char *stream, int stream_ptr)
{
	while (is_delim(stream[stream_ptr]) && stream[stream_ptr])
	{
		stream_ptr += 1;
	}
	return (stream_ptr);
}
