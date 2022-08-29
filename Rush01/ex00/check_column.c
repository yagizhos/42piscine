/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:36:45 by yhos              #+#    #+#             */
/*   Updated: 2022/08/21 16:36:46 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_column_top(int grid[4][4], int tab, int col)
{
	int	i;
	int	mem;
	int	comp;

	i = 0;
	mem = 0;
	comp = 0;
	while (i < 4)
	{
		if (mem < grid[i][col])
		{
			mem = grid[i][col];
			comp++;
		}
		i++;
	}
	if (tab == comp)
		return (1);
	return (0);
}

int	check_column_bottom(int grid[4][4], int tab, int col)
{
	int	i;
	int	mem;
	int	comp;

	i = 3;
	mem = 0;
	comp = 0;
	while (i >= 0)
	{
		if (mem < grid[i][col])
		{
			mem = grid[i][col];
			comp++;
		}
		i--;
	}
	if (tab == comp)
		return (1);
	return (0);
}

int	check_column(int grid[4][4], int *tab)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (i < 4)
	{
		if (check_column_top(grid, tab[i], i))
			if (check_column_bottom(grid, tab[4 + i], i))
				comp++;
		i++;
	}
	if (comp == 4)
		return (1);
	return (0);
}
