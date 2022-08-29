/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:47:21 by dpentlan          #+#    #+#             */
/*   Updated: 2022/08/29 20:49:30 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map_solve.h"
#include "ft_map_init.h"
#include "ft_map_load.h"
#include <stdio.h>
int	map_solve(char *map_file)
{
	t_map_info	map_info;
	char		**map;

	map_info = map_init(map_file);
	if (map_info == 0)
		return (-1);
	//call map load to load into ram the map data
	map = map_load(map_file, map_info);
	if (!map)
		return (-1);
	int i = 0;
	printf("%d\n", map_info->height);
	while (i < map_info->height)
	{
			printf("%s\n", map[i]);
			i++;
	}
	//call functions to actually solve the problem
	//write to map solution
	//free map arrays
	//free struct created in map init
	//return 0 on success, -1 on error
	free(map);
	return (0);
}
