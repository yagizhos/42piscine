/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:41:18 by yhos              #+#    #+#             */
/*   Updated: 2022/08/21 14:41:24 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	put_num_in_tab(int all_p[24][4], int *row, int num)
{
	all_p[*row][0] = num % 10;
	all_p[*row][1] = ((num % 100) / 10);
	all_p[*row][2] = ((num / 100) % 10);
	all_p[*row][3] = num / 1000;
	(*row)++;
}

void	row_generator(int all_p[24][4])
{
	int	num;
	int	row;

	row = 0;
	num = 1234;
	while (num <= 4321)
	{
		if ((num % 10 != ((num % 100) / 10) && num % 10 != ((num / 100) % 10)
				&& num % 10 != num / 1000)
			&& (((num % 100) / 10) != ((num / 100) % 10)
				&& ((num % 100) / 10) != num / 1000)
			&& (((num / 100) % 10) != num / 1000))
		{
			if ((num % 10 >= 1 && num % 10 <= 4) && (((num % 100) / 10) >= 1
					&& ((num % 100) / 10 <= 4)) && (((num / 100) % 10) >= 1
					&& ((num / 100) % 10) <= 4) && ((num / 1000) >= 1
					&& (num / 1000) <= 4))
				put_num_in_tab(all_p, &row, num);
		}
		num++;
	}
}

void	put_num_in_row(int grid[4][4], int try, int row, int all_p[24][4])
{
	grid[row][0] = all_p[try][0];
	grid[row][1] = all_p[try][1];
	grid[row][2] = all_p[try][2];
	grid[row][3] = all_p[try][3];
}

void	show(int grid[4][4])
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = 48 + grid[i][j];
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
