/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 07:44:39 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/12 13:41:17 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		parse(char *stream)
{
	char		**split_input;
	t_tokens	*tokens;

	if (!stream)
	{
		return ;
	}
	split_input = split_parse(stream);
	tokens = tokenize(split_input);
}
