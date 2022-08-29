/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:04:54 by yhos              #+#    #+#             */
/*   Updated: 2022/08/25 19:26:56 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_final_size(int size, char **strs, char *sep)
{
	int	s;
	int	i;
	int	j;
	int	k;

	s = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			s++;
			j++;
		}
		i++;
	}
	k = 0;
	while (sep[k])
		k++;
	s += k * (size - 1);
	return (s);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*r;
	int		j;

	if (size <= 0)
	{
		r = malloc(sizeof(char));
		if (!r)
			return (0);
		*r = '\0';
		return (r);
	}
	j = 0;
	r = malloc(sizeof(char) * (find_final_size(size, strs, sep) + 1));
	if (!r)
		return (0);
	while (j < size)
	{
		ft_strcat(r, strs[j]);
		if (j + 1 != size)
			ft_strcat(r, sep);
		j++;
	}
	r[j] = '\0';
	return (r);
}
