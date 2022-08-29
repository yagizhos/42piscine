/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:54:15 by yhos              #+#    #+#             */
/*   Updated: 2022/08/24 12:56:13 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	j = 0;
	while (src[j])
	{
		s[j] = src[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*r;
	int			i;

	r = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!r)
		return (0);
	i = 0;
	while (i < ac)
	{
		r[i].size = ft_strlen(av[i]);
		r[i].str = av[i];
		r[i].copy = ft_strdup(av[i]);
		if (r[i].copy == 0)
			return (0);
		i++;
	}
	r[i].str = 0;
	return (r);
}
