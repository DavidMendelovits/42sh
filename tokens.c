/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:37:55 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/13 05:53:50 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				extract_token(char **input, int *ptr, t_tokens **tokens)
{
	if (and_check(input[ptr]))
	{
			
	}
	else if (or_check(input[ptr]))
	{

	}
	else if (pipe_check(input[ptr]))
	{

	}
	else if (command_check(input[ptr]))
	{

	}
	else if (expansion_check(input[ptr]))
	{

	}

}

void			init_tokens(t_tokens **tokens)
{
	(*tokens)->_and = NULL;
	(*tokens)->_or = NULL;
	(*tokens)->_pipe = NULL;
	(*tokens)->_command = NULL;
	(*tokens)->_arguments = NULL;
	(*tokens)->_expansions = NULL;
}

t_tokens		*tokenize(char **split)
{
	int			ptr;
	t_tokens	*tokens;

	init_tokens(&tokens);
	ptr = 0;
	while (split[ptr])
	{
		if (!extract_token(split, &ptr, &tokens))
		{
			printf("\nerror...\ninvalid token!\n");
			return (NULL);
		}
		else
			ptr += 1;
	}

}
