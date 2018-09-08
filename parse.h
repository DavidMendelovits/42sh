/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:19:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/08 08:21:45 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct		s_strsplit
{
	char		**strings;
	int			ptr;
	int			word_count;
	int			is_quote:1;
	int			reserved_word:1;
}					t_strsplit;

void		parse(char *stream);
char		*primary_parse(char *stream);
void		print_words(char **words);
char		**parse_strsplit(char *stream);
int			parse_word_count(char *stream);
int			skip_delim(char *stream, int stream_ptr);
int			is_delim(char c);
