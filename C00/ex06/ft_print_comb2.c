/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:11:53 by yhos              #+#    #+#             */
/*   Updated: 2022/08/11 13:13:37 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*int_to_string(int t);
void	print(int i, int j);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		while (j < 100)
		{
			if (i != j)
				print(i, j);
			j++;
		}
		j = i + 1;
		i++;
	}
}

char	*int_to_string(int t)
{
	static char	s[2];

	if (t < 10)
	{
		s[0] = '0';
		s[1] = t + '0';
	}
	else
	{
		s[0] = t / 10 + '0';
		s[1] = t % 10 + '0';
	}
	return (s);
}

void	print(int i, int j)
{
	write(1, int_to_string(i), 2);
	write(1, " ", 1);
	write(1, int_to_string(j), 2);
	if (i != 98)
		write(1, ", ", 2);
}
