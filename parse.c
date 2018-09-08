/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 07:44:39 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/08 07:44:46 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		parse(char *stream)
{
	char		*parsed_input;

	if (!stream)
	{
		return ;
	}
	parsed_input = primary_parse(stream);
}
