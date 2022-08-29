/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:46:35 by yhos              #+#    #+#             */
/*   Updated: 2022/08/18 18:15:53 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
		print(nb);
}
