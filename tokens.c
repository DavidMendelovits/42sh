/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:37:55 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/12 15:26:34 by dmendelo         ###   ########.fr       */
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
	(*tokens)->_and = ft_strdup("0");
	(*tokens)->_or = ft_strdup("0");
	(*tokens)->_pipe = ft_strdup("0");
	(*tokens)->_command = ft_strdup("0");
	(*tokens)->_arguments = ft_strdup("0");
	(*tokens)->_expansions = ft_strdup("0");
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
