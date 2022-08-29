/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:49:37 by yhos              #+#    #+#             */
/*   Updated: 2022/08/23 11:00:28 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*r;
	int	n;
	int	i;

	if (min >= max)
		return (0);
	n = max - min;
	r = malloc(sizeof(int) * n);
	if (!r)
		return (0);
	i = 0;
	while (i < n)
	{
		r[i] = min;
		min++;
		i++;
	}
	return (r);
}
