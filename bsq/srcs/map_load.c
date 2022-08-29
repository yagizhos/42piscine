/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:28:06 by dpentlan          #+#    #+#             */
/*   Updated: 2022/08/29 21:07:50 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// functions for loading map file into an array for use by other functions.
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_map_init.h"

#include <stdio.h>

void	free_map(char **map)
{

}

int	skip_to(int line, int file_desc)
{
	int		result;
	int		skip_to;
	char	buf;

	result = 1;
	skip_to = 0;
	while (result > 0 && skip_to != line)
	{
		result = read(file_desc, &buf, 1);
		if (buf == '\n')
			skip_to++;
	}
	if (result == -1)
		return (-1);
	return (skip_to);
}

int	find_line_size(int line, char *file)
{
	int		file_desc;
	int		result;
	int		line_size;
	char	buf;

	result = 1;
	line_size = 0;
	buf = 0;
	file_desc = open(file, O_RDONLY);
	if (file_desc == -1)
		return (-1);
	if (skip_to(line, file_desc) == -1)
	{
		close(file_desc);
		return (-1);
	}
	while (result > 0 && buf != '\n')
	{
		result = read(file_desc, &buf, 1);
		line_size++;
	}
	close(file_desc);
	if (result == -1)
		return (-1);
	return (line_size - 1);
}

char	**map_load(char *file, t_map_info map_info)
{
	char	**map;
	char	buf;
	int		file_desc;
	int		line_size;
	int		result;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * map_info->height);
	if (!map)
		return (0);
	file_desc = open(file, O_RDONLY);
	if (file_desc == -1)
		return (0);
	line_size = find_line_size(1, file);
	printf("%d\n", line_size);
	if (line_size == -1 || skip_to(1, file_desc) == -1)
		return (0);
	i = 0;
	j = 0;
	map[i] = malloc(sizeof(char) * (line_size + 1));
	while (result != -1 && i < map_info->height)
	{
		result = read(file_desc, &buf, 1);
		if (buf == '\n' && result != 0)
		{
			map[i][j++] = '\0';
			i++;
			if (i != map_info->height)
				map[i] = malloc(sizeof(char) * (line_size + 1));
			j = 0;
		}
		else
			map[i][j++] = buf;
	}
	if (result == -1)
	{
		free(map);
		return (0);
	}
	return (map);
}
