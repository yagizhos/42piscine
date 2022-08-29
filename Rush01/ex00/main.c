/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:58:35 by yhos              #+#    #+#             */
/*   Updated: 2022/08/21 17:01:07 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize(int grid[4][4]);
void	put_num_in_tab(int all_p[24][4], int *row, int num);
void	row_generator(int all_p[24][4]);
void	put_num_in_row(int grid[4][4], int try, int row, int all_p[24][4]);
void	show(int grid[4][4]);
int		check_row_left(int *grid, int max, int comp);
int		check_row_right(int *grid, int max, int comp);
int		check_row(int *grid, int *tab, int row);
int		check_column_top(int grid[4][4], int tab, int col);
int		check_column_bottom(int grid[4][4], int tab, int col);
int		check_column(int grid[4][4], int *tab);

int	*construct_tab(char *s, int *tab)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (s[i] != '\0')
	{
		if (s[0] < '1' || s[0] > '4')
		{
			tab[0] = 9;
			break ;
		}
		if (s[i] >= '1' && s[i] <= '4')
		{
			tab[val] = (s[i] - 48);
			val++;
			if (s[i + 1] != '\0')
				if (s[i + 1] != ' ' || s[i + 2] < '1' || s[i + 2] > '4')
					tab[0] = 9;
		}
		i++;
	}
	if (val != 16)
		tab[0] = 9;
	return (tab);
}

int	no_dup_in_column(int grid[4][4], int row)
{
	int	col;
	int	row_below;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			row_below = row + 1;
			while (row_below < 4)
			{
				if (grid[row][col] == grid[row_below][col])
					return (0);
				row_below++;
			}
			row++;
		}
		col++;
	}
	return (1);
}

int	backtrack(int grid[4][4], int *tab, int row)
{
	int	try;
	int	all_p[24][4];

	try = 0;
	row_generator(all_p);
	if (row == 4)
	{
		if (no_dup_in_column(grid, row) && check_column(grid, tab))
		{
			show(grid);
			return (1);
		}
	}
	while (try < 24)
	{
		put_num_in_row(grid, try, row, all_p);
		if (check_row(grid[row], tab, row))
			if (backtrack(grid, tab, row + 1))
				return (1);
		try++;
	}
	if (try == 24 && row == 0)
		write(1, "Error\n", 6);
	return (0);
}

void	rush(int *tab)
{
	int	grid[4][4];
	int	all_possibilities[24][4];

	initialize(grid);
	row_generator(all_possibilities);
	backtrack(grid, tab, 0);
}

int	main(int argc, char *argv[])
{
	int	tab[16];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	construct_tab(argv[1], tab);
	if (tab[0] == 9)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	rush(tab);
	return (0);
}
