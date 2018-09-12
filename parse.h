/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:19:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/12 15:15:18 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "libft/libft.h"

typedef struct		s_strsplit
{
	char		**strings;
	int			ptr;
	int			word_count;
	int			is_quote:1;
	int			reserved_word:1;
}					t_strsplit;

typedef struct		s_tokens
{
	//think about how we want mark each token
	//string[0] = number of tokens to look for?
	//delimited by a special char... maybe '&'?
	char			*_and;
	char			*_or;
	char			*_pipe;
	char			*_command;
	char			*_arguments;
	char			*_expansions;
}					t_tokens;

void		parse(char *stream);
char		**split_parse(char *stream);
void		print_words(char **words);
char		**parse_strsplit(char *stream);
int			parse_arg_count(char *stream);
int			skip_delim(char *stream, int stream_ptr);
int			is_delim(char c);
int			is_quote(char c);
int			is_special_char(char c);
int			is_start_bracket(char c);
int			is_end_bracket(char c);
int			find_end_quote(char *stream, int *ptr);
