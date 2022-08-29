/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:58:36 by yhos              #+#    #+#             */
/*   Updated: 2022/08/13 14:14:27 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(int l, char m, char c)
{
	int	i;

	i = l - 2;
	ft_putchar(c);
	while (i-- > 0)
		ft_putchar(m);
	ft_putchar(c);
	ft_putchar('\n');
}

void	print_mid(int l, int r, char c)
{
	int	i;
	int	j;
	int	t;

	i = l - 2;
	j = r - 2;
	while (i-- > 0)
	{
		t = j;
		ft_putchar(c);
		while (t-- > 0)
			ft_putchar(' ');
		if (r != 1)
			ft_putchar(c);
		ft_putchar('\n');
	}
}

void	print_rectangle(int i, int j)
{
	if (i < 1 || j < 1)
		return ;
	else if (i == 1 && j == 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else if (i == 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
		print_mid(j, i, '|');
		ft_putchar('o');
		ft_putchar('\n');
	}
	else if (j == 1)
		print_row(i, '-', 'o');
	else
	{
		print_row(i, '-', 'o');
		print_mid(j, i, '|');
		print_row(i, '-', 'o');
	}
}

void	rush(int i, int j)
{
	print_rectangle(i, j);
}
