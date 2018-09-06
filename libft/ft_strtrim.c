/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:25:30 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 19:46:38 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		i;
	int		j;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n') && j--)
		start++;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && j--)
		end--;
	if (!(result = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	while (start <= end)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
