/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:05:21 by yhos              #+#    #+#             */
/*   Updated: 2022/08/24 20:05:23 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	base_is_valid(char *base)
{
	int	b;
	int	i;

	b = 0;
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
	return (1);
}

int	construct_int(char *s, char *base, int z)
{
	int	b;
	int	r;
	int	p;
	int	i;

	r = 0;
	p = 1;
	b = 0;
	while (base[b])
		b++;
	while (z > 0)
	{
		i = 0;
		while (base[i])
		{
			if (s[z - 1] == base[i])
				break ;
			i++;
		}
		r += (i * p);
		p *= b;
		z--;
	}
	return (r);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	char	*num_start;

	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!(base_is_valid(base)))
		return (0);
	num_start = str;
	i = 0;
	while (is_in_base(num_start[i], base))
		i++;
	if (i != 0)
		return (sign * construct_int(num_start, base, i));
	return (0);
}
