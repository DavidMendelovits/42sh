/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:15:04 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/06 15:31:18 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				skip_delim(char *stream, int stream_ptr)
{
	while (is_delim(stream[stream_ptr]) && stream[stream_ptr])
	{
		stream_ptr += 1;
	}
	return (stream_ptr);
}

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

char			**parse_strsplit(char *stream)
{
	char		**strings;
	int			strings_ptr;
	int			sp;
	int			word_count;
	int			begin;

	word_count = parse_word_count(stream);
	printf("word_count = %d\n", word_count);
	strings = malloc(sizeof(strings) * (word_count + 1));
	sp = 0;
	strings_ptr = 0;
	printf("strlen(stream) = %d\n", (int)ft_strlen(stream));
	while (stream[sp] != '\0')
	{
		printf("sp = %d\n", sp);
		if (!is_delim(stream[sp]))
		{
			begin = sp;
			while (!is_delim(stream[sp]) && stream[sp])
				sp += 1;
			printf("sp = %d\n", sp);
			strings[strings_ptr] = ft_strdup_range(stream, begin, sp - 1);
			printf("string[%d] = %s\n", strings_ptr, strings[strings_ptr]);
			strings_ptr += 1;
		}
		else
			sp = skip_delim(stream, sp);
	}
	strings[strings_ptr] = NULL;
	return (strings);
}

int				is_delim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\\')
	{
		return (1);
	}
	return (0);
}

void		print_words(char **words)
{
	int			i;

	i = 0;
	while (words[i])
	{
		printf("%s\n", words[i]);
		i += 1;
	}
}


char		*strjoin_space(char *stream, char **strings, int ptr)
{

}

void		free_append(char **stream, char **strings, int ptr)
{
	char	*tmp;

	tmp = ft_memalloc(ft_strlen(*stream) + ft_strlen(strings[ptr]) + 2);
	tmp = strjoin_space(*stream, strings, ptr);
}

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

char		*primary_parse(char *stream)
{
	char		**strings;
	char		*condensed_stream;
	
	strings = parse_strsplit(stream);
	print_words(strings);
	condensed_stream = condense_stream(strings);
	free_2d_ptr(strings);
	return (stream);
}

void		parse(char *stream)
{
	char		*parsed_input;

	if (!stream)
	{
		return ;
	}
	parsed_input = primary_parse(stream);
}
