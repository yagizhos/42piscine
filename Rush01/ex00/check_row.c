/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:12:00 by yhos              #+#    #+#             */
/*   Updated: 2022/08/21 16:12:01 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_left(int *grid, int max, int comp)
{
	int	i;
	int	mem;
	int	val;

	i = 0;
	mem = 0;
	val = 0;
	while (i < 4)
	{
		if (mem < grid[i])
		{
			mem = grid[i];
			val++;
		}
		i++;
	}
	i--;
	if (max == val)
		comp++;
	return (comp);
}

int	check_row_right(int *grid, int max, int comp)
{
	int	i;
	int	mem;
	int	val;

	i = 3;
	mem = 0;
	val = 0;
	while (i >= 0)
	{
		if (mem < grid[i])
		{
			mem = grid[i];
			val++;
		}
		i--;
	}
	if (max == val)
		comp++;
	return (comp);
}

int	check_row(int *grid, int *tab, int row)
{
	int	max;
	int	comp;

	comp = 0;
	max = tab[8 + row];
	comp = check_row_left(grid, max, comp);
	max = tab[12 + row];
	comp = check_row_right(grid, max, comp);
	if (comp == 2)
		return (1);
	return (0);
}
