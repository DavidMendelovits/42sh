/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:15:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/08 09:03:45 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				parse_word_count(char *stream)
{
	int			sp;
	int			count;

	sp = 0;
	while (stream[sp])
	{
		if (is_delim(stream[sp]))
		{
			sp = skip_delim(stream, sp);
		}
		if (!stream[sp])
		{
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

char			**parse_seperate_quotes(char **_stream)
{
	int				_stream_ptr;
	char			**stream;
	int				stream_ptr;

	return (_stream);
}

char			**parse_strsplit(char *stream)
{
	int				sp;
	int				begin;
	t_strsplit		split;

	split.word_count = parse_word_count(stream);
	
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
		else if (is_special_char(stream[sp]))
		{

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
char		*primary_parse(char *stream)
{
	char		**strings;
//	char		*condensed_stream;
	
	strings = parse_strsplit(stream);
	print_words(strings);
//	condensed_stream = condense_stream(strings);
//	free_2d_ptr(strings);
	return (stream);
}
