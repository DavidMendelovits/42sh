/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:19:09 by dmendelo          #+#    #+#             */
/*   Updated: 2018/09/06 15:31:20 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

void		parse(char *stream);
char		*primary_parse(char *stream);
void		print_words(char **words);
char		**parse_strsplit(char *stream);
int			parse_word_count(char *stream);
int			skip_delim(char *stream, int stream_ptr);
int			is_delim(char c);
