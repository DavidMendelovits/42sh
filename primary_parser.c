/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:15:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/12 14:00:21 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*

			while (stream[sp] && stream[sp - 1])
			{
				sp += 1;
				if (is_quote(stream[sp]))
				{
					count += 1;			
				}

			}
			if (!stream[sp])
				printf("error. Missing end-quote\n");
*/

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
		else if (is_delim(stream[sp]))
		{
			sp = skip_delim(stream, sp);
			if (!stream[sp])
				return (count);
		}
		else
		{
			count += 1;
			while (!is_delim(stream[sp]) && stream[sp])
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
		if (is_quote(stream[sp]))
		{
			sp = dup_quote_contents(sp, stream, &split);
		}
		if (is_start_bracket)
		{
			sp = dup_bracket_contents(sp, stream, &split);
		}
		else if (is_special_char(stream[sp]))
		{
			sp = dup_special_case(sp, stream, &split);
		}
		else if (!is_delim(stream[sp]))
		{
			begin = sp;
			while (!is_delim(stream[sp]) && stream[sp])
				sp += 1;
	
			printf("sp = %d\n", sp);
	
			split.strings[split.ptr] = ft_strdup_range(stream, begin, sp - 1);

			printf("string[%d] = %s\n", split.ptr, split.strings[split.ptr]);
	
			split.ptr += 1;
		}
		else
			sp = skip_delim(stream, sp);
	}
	split.strings[split.ptr] = NULL;
	return (split.strings);
}

/*
char		*strjoin_space(char *stream, char **strings, int ptr)
{

}
*/

/*
void		free_append(char **stream, char **strings, int ptr)
{
	char	*tmp;


	tmp = ft_memalloc(ft_strlen(*stream) + ft_strlen(strings[ptr]) + 2);
	tmp = strjoin_space(*stream, strings, ptr);
}
*/

/*
char		*condense_stream(char **strings)
{
	int			strings_ptr;
	char		*condensed_stream;

	condensed_stream = ft_strdup(strings[0]);
	strings_ptr = 1;
	while (strings[strings_ptr])
	{
		free_append(&condensed_stream, strings, strings_ptr);
	}
}
*/
char		**split_parse(char *stream)
{
	char		**strings;
//	char		*condensed_stream;
	
	strings = parse_strsplit(stream);
	assert(strings);
	print_words(strings);
//	condensed_stream = condense_stream(strings);
//	free_2d_ptr(strings);
	return (stream);
}
