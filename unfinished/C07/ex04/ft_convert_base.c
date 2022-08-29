/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:46:54 by yhos              #+#    #+#             */
/*   Updated: 2022/08/23 15:53:30 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_base(char c, char *base);
int	base_is_valid(char *base);
int	construct_int(char *s, char *base, int z);
int	ft_atoi_base(char *str, char *base);

char	*convert(char *base, int l, int b, int negative)
{
	char	*r;
	int		n[255];
	int		i;
	int		j;

	i = 0;
	while (l > 0)
	{
		n[i] = l % b;
		l /= b;
		i++;
	}
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (0);
	j = 0;
	if (negative)
		r[j++] = '-';
	while (i > 0)
		r[j++] = base[n[--i]];
	r[j] = '\0';
	return (r);
}

char	*return_val(char *base, int nbr, int b)
{
	char	*r;
	long	l;
	int		negative;

	l = (long)nbr;
	negative = 0;
	if (l < 0)
	{
		l *= -1;
		negative = 1;
	}
	if (l == 0)
	{
		r = malloc(sizeof(char) * 2);
		if (!r)
			return (0);
		r[0] = base[0];
		r[1] = '\0';
		return (r);
	}
	return (convert(base, l, b, negative));
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		b;
	int		i;

	b = 0;
	i = 0;
	if (!base[b])
		return (0);
	while (base[b])
	{
		i = 0;
		while (base[i])
		{
			if (b != i && base[b] == base[i])
				return (0);
			i++;
		}
		if (base[b] == '+' || base[b] == '-'
			|| base[b] <= 32 || base[b] == 127)
			return (0);
		b++;
	}
	if (b < 2)
		return (0);
	return (return_val(base, nbr, b));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	t;

	t = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(t, base_to));
}
