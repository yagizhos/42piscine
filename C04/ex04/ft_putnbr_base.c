/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:46:40 by yhos              #+#    #+#             */
/*   Updated: 2022/08/23 21:59:19 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert_print(char *base, int nbr, int b)
{
	int		n[255];
	int		i;
	long	l;

	l = (long)nbr;
	i = 0;
	if (l == 0)
		ft_putchar(base[0]);
	else
	{
		if (l < 0)
		{
			l *= -1;
			ft_putchar('-');
		}
		while (l > 0)
		{
			n[i] = l % b;
			l /= b;
			i++;
		}
		while (i > 0)
			ft_putchar(base[n[--i]]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	int		i;

	b = 0;
	i = 0;
	if (!base[b])
		return ;
	while (base[b])
	{
		i = 0;
		while (base[i])
		{
			if (b != i && base[b] == base[i])
				return ;
			i++;
		}
		if (base[b] == '+' || base[b] == '-'
			|| base[b] <= 32 || base[b] == 127)
			return ;
		b++;
	}
	if (b < 2)
		return ;
	convert_print(base, nbr, b);
}
