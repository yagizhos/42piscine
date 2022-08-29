/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:55:15 by yhos              #+#    #+#             */
/*   Updated: 2022/08/10 22:43:16 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_print(char i, char j, char k);

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 48;
	j = 48;
	k = 48;
	while (i < 58)
	{
		while (j < 58)
		{
			while (k < 58)
			{
				check_print(i, j, k);
				k++;
			}
			k = j + 1;
			j++;
		}
		j = i + 1;
		i++;
	}
}

void	check_print(char i, char j, char k)
{
	char	comb[3];

	if (i != j && i != k && j != k)
	{
		comb[0] = i;
		comb[1] = j;
		comb[2] = k;
		write(1, comb, 3);
		if (comb[0] != '7')
			write(1, ", ", 2);
	}
}
