/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:38:08 by djanusz           #+#    #+#             */
/*   Updated: 2022/08/13 16:36:20 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x, char start, char mid, char end)
{
	int	i;

	i = 2;
	ft_putchar(start);
	while (i < x)
	{
		ft_putchar(mid);
		i++;
	}
	ft_putchar(end);
	ft_putchar('\n');
}

void	ft_print_column(int y)
{
	int	i;

	i = 2;
	ft_putchar('A');
	ft_putchar('\n');
	while (i < y)
	{
		ft_putchar('B');
		ft_putchar('\n');
		i++;
	}
	ft_putchar('C');
	ft_putchar('\n');
}

int	ft_check(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (1);
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
		return (1);
	}
	if (x == 1)
	{
		ft_print_column(y);
		return (1);
	}
	if (y == 1)
	{
		ft_print_line(x, 'A', 'B', 'C');
		return (1);
	}
	return (0);
}

void	rush(int x, int y)
{
	int	i;

	i = 2;
	if (ft_check(x, y))
	{
		return ;
	}
	ft_print_line(x, 'A', 'B', 'C');
	while (i < y)
	{
		ft_print_line(x, 'B', ' ', 'B');
		i++;
	}
	ft_print_line(x, 'C', 'B', 'A');
}
