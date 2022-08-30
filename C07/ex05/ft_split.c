/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:32:28 by yhos              #+#    #+#             */
/*   Updated: 2022/08/26 12:41:29 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int	find_array_size(char *str, char *charset)
{
	int	s;
	int	i;

	s = 0;
	i = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			i++;
		else
		{
			s++;
			while (!is_in_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (s);
}

int	construct_string(char **r, char *str, char *charset, int strcount)
{
	int	strlen;
	int	j;

	strlen = 0;
	j = 0;
	while (!is_in_charset(str[j], charset) && str[j])
	{
		strlen++;
		j++;
	}
	r[strcount] = malloc(sizeof(char) * (strlen + 1));
	if (!r[strcount])
		return (0);
	j = 0;
	while (!is_in_charset(str[j], charset) && str[j])
	{
		r[strcount][j] = str[j];
		j++;
	}
	r[strcount][j] = 0;
	return (j);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	char	*newstr;
	int		i;
	int		strcount;

	strcount = 0;
	i = 0;
	r = malloc(sizeof(char *) * (find_array_size(str, charset) + 1));
	if (!r)
		return (0);
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			i++;
		else
		{
			newstr = str + i;
			if (!construct_string(r, newstr, charset, strcount))
				return (0);
			else
				i += construct_string(r, newstr, charset, strcount++);
		}
	}
	r[strcount] = 0;
	return (r);
}
