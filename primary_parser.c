/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:15:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/13 06:38:08 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				find_end_quote(char *stream, int *ptr)
{
	*ptr += 1;
	while (stream[*ptr])
	{
		if (is_quote(stream[*ptr]))
		{
			*ptr += 1;
			return (1);
		}
		*ptr += 1;
	}
	return (0);
}

int				parse_arg_count(char *stream)
{
	int			sp;
	int			count;

	sp = 0;
	while (stream[sp])
	{
		if (is_quote(stream[sp]))
		{
			if (find_end_quote(stream, &sp))
				count += 1;
			else
			{
				printf("\n\nError. Missing end quote\n");
				return (0);
			}
		}
		else if (is_whitespace(stream[sp]))
		{
			sp = skip_whitespace(stream, sp);
			if (!stream[sp])
				return (count);
		}
		else
		{
			count += 1;
			while (!is_whitespace(stream[sp]) && stream[sp])
			{
				sp += 1;
			}
		}
	}
	return (count);
}
/*
char			**parse_seperate_quotes(char **_stream)
{
	int				_stream_ptr;
	char			**stream;
	int				stream_ptr;

	return (_stream);
}
*/

int				dup_quote_contents(int ptr, char *stream, t_strsplit *split)
{
	int			begin;
	char		quote;

	begin = ptr;
	quote = stream[ptr];
	ptr += 1;
	while (stream[ptr])
	{
		if (stream[ptr] == quote)
		{
			split->strings[split->ptr] = ft_strdup_range(stream, begin, ptr);
			printf("function->dup_quote_contents: %s\n", split->strings[split->ptr]);
			split->ptr += 1;
			return (ptr + 1);
		}
		ptr += 1;
	}
	return (ptr);
}

int				dup_redirection(int ptr, char *stream, t_strplit *split)
{
	if (stream[ptr] == '>' && stream[ptr + 1] == '>')
	{
		split->strings[split->ptr] = ft_strdup_range(stream, ptr, ptr + 1);
		ptr += 1;
	}
	else if (stream[ptr] == '>')
	{
		split->strings[split->ptr] = ft_strdup_range(stream, ptr, ptr);
	}
	else if (stream[ptr] == '<')
	{
		split->strings[split->ptr] = ft_strdup_range(stream, ptr, ptr);
	}
	else if (stream[ptr] == '|' && stream[ptr + 1] != '|')
	{
		split->strings[split->ptr] = ft_strdup_range(stream, ptr, ptr);
	}
	printf("\nfunction->dup_redirection\n");
	printf("strings[%d] = %s\n", split->ptr, split->strings[split->ptr]);
	split->ptr += 1;
	return (ptr + 1);
}

int				dup_logical_operator(int ptr, char *stream, t_strsplit *split)
{
	if (stream[ptr] == '&' && stream[ptr + 1] == '&')
	{
		split->strings[split->ptr] = ft_strdup_range(stream, ptr, ptr + 1);
	}
	else if (stream[ptr] == '|' && stream[ptr + 1] == '|')
	{
		split->strings[split->ptr] = ft_strdup_range(stream, ptr, ptr + 1);
	}
	printf("\nfunction->dup_logical_operator\n");
	printf("strings[%d] = %s\n", split->ptr, split->strings[split->ptr]);
	split->ptr += 1;
	return (ptr + 2);
}

char			**parse_strsplit(char *stream)
{
	int				sp;
	int				begin;
	t_strsplit		split;

	split.word_count = parse_arg_count(stream);
	if (!split.word_count)
		return (NULL);
	printf("word_count = %d\n", split.word_count);
	
	split.strings = malloc(sizeof(split.strings) * (split.word_count + 1));
	sp = 0;
	split.ptr = 0;
	printf("strlen(stream) = %d\n", (int)ft_strlen(stream));
	while (stream[sp] != '\0')
	{
		printf("sp = %d\n", sp);
		if (!is_whitespace(stream[sp]))
		{
			begin = sp;
			while (!is_whitespace(stream[sp]) && stream[sp])
			{
				if (is_quote(stream[sp]))
				{
					split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);
					printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
					split.ptr += 1;
					sp = dup_quote_contents(sp, stream, &split);
					begin = sp;
				}
				else if (is_redirection(stream[sp]))
				{
					split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);
					printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
					split.ptr += 1;
					sp = dup_redirection(sp, stream, &split);
					begin = sp;
				}
				else if (is_logical_operator(stream[sp], stream[sp + 1]))
				{

					split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);
					printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
					split.ptr += 1;
					sp = dup_logical_operator(sp, stream, &split);
					begin = sp;
				}
				else if (is_glob(stream, sp))
				{
					split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);
					printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
					split.ptr += 1;
					sp = dup_glob(sp, stream, &split);
					begin = sp;
				}
				else if (stream[sp] == ';')
				{
					split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);
					printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
					split.ptr += 1;
					sp = dup_seperator(sp, stream, &split);
					begin = sp;
				}
				else
				{
					sp += 1;
				}
				printf("sp = %d\n", sp);
			}
			if (!is_whitespace(stream[begin]))
			{
				split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);
				printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
				split.ptr += 1;
			}
		}
		else
			sp = skip_whitespace(stream, sp);
	}
	split.strings[split.ptr] = NULL;
	return (split.strings);
}

char		**split_parse(char *stream)
{
	char		**strings;
	
	strings = parse_strsplit(stream);
	assert(strings);
	print_words(strings);
	return (stream);
}
