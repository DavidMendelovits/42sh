/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 07:45:05 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/13 05:53:44 by dmendelo         ###   ########.fr       */
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
	if (c == '"' || c == '\'')
	{
		return (1);
	}
	return (0);
}

int				is_redirection(char c1, char c2)
{
	if (c1 == '>' || c1 == '<' || (c1 == '|' && c2 != '|') ||
		   	(c1 == '>' && c2 == '>'))
	{
		return (1);
	}
	return (0);

}

int				is_logical_operator(char c1, char c2)
{
	if ((c1 == '&' && c2 == '&') || (c1 == '|' && c2 == '|'))
	{
		return (1);
	}
	return (0);
}

int				is_expansion_char(char c)
{
	if (c == '$' || c == '*')
	{
		return (1);
	}
	return (0);
}

int			is_special_char(char c)
{
	if (c == '!' || c == '`')
	{
		return (1);
	}
	return (0);
}

int				is_start_bracket(char c)
{
	if (c == '(' || c == '[' || c == '{') 
	{
		return (1);
	}
	return (0);
}

int				is_end_bracket(char c)
{
	if (c == ')' || c == ']' || c == '}')
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
