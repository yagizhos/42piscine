/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:58:50 by yhos              #+#    #+#             */
/*   Updated: 2022/08/24 13:09:21 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	reverse(char *s, int l)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	b = l - 1;
	while (a < b)
	{
		c = s[a];
		s[a] = s[b];
		s[b] = c;
		a++;
		b--;
	}
}

void	print(int num)
{
	int		n;
	int		l;
	char	s[11];

	l = 0;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	n = num;
	while (n != 0)
	{
		s[l] = n % 10 + '0';
		n /= 10;
		l++;
	}
	s[l] = '\0';
	reverse(s, l);
	write(1, s, l);
}

void	ft_putnbr_nl(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
		print(nb);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr_nl(par[i].str);
		ft_putnbr_nl(par[i].size);
		ft_putstr_nl(par[i].copy);
		i++;
	}
}
