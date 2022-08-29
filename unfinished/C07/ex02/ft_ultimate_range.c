/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:01:18 by yhos              #+#    #+#             */
/*   Updated: 2022/08/23 12:04:11 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	n;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	n = max - min;
	*range = malloc(sizeof(int) * n);
	if (!*range)
		return (-1);
	i = 0;
	while (i < n)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (n);
}
