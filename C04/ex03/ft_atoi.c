/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:31:37 by yhos              #+#    #+#             */
/*   Updated: 2022/08/17 18:44:01 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	if (!(c > 47 && c < 58))
		return (0);
	return (1);
}

int	construct_int(char *s, int l)
{
	int	r;
	int	d;

	r = 0;
	d = 1;
	while (l > 0)
	{
		r += (s[l - 1] - 48) * d;
		d *= 10;
		l--;
	}
	return (r);
}

int	ft_atoi(char *src)
{
	int		i;
	int		sign;
	char	*num_start;

	i = 0;
	sign = 1;
	while ((*src > 8 && *src < 14) || *src == 32)
		src++;
	while (*src == '-' || *src == '+')
	{
		if (*src == '-')
			sign *= -1;
		src++;
	}
	num_start = src;
	while (is_numeric(num_start[i]))
		i++;
	if (i != 0)
		return (sign * construct_int(num_start, i));
	return (0);
}
