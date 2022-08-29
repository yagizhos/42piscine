/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:25:41 by dpentlan          #+#    #+#             */
/*   Updated: 2022/08/29 19:25:43 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map_init.h"
#include "ft_map_load.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int	map_num_copy(char *read_buffer, t_map_info map_info)
{
	int		i;

	i = 0;
	map_info->height = 0;
	while (read_buffer[i] >= '0' && read_buffer[i] <= '9')
	{
		map_info->height *= 10;
		map_info->height += read_buffer[i] - '0';
		i++;
	}
	return (i);
}

int	map_copy_info(char *read_buffer, t_map_info map_info)
{
	int		result;
	int		i;

	i = 0;
	result = 1;
	result = map_num_copy(read_buffer, map_info);
	if (result == -1)
		return (-1);
	i = result;
	map_info->space = read_buffer[i];
	i++;
	map_info->obs = read_buffer[i];
	i++;
	map_info->fill = read_buffer[i];
	i++;
	return (i);
}

int	read_buffer_build(char *read_buffer, int fildes, int line_size)
{
	int	i;	
	int	result;

	i = 0;
	while (i < line_size)
	{
		result = read(fildes, &read_buffer[i], 1);
		if (result < 1)
			return (-1);
		i++;
	}
	return (0);
}

t_map_info	map_init(char *map_file)
{
	int			fildes;		
	int 		line_size;
	char		*read_buffer;
	t_map_info	map_info;
	
	map_info = NULL;
	read_buffer = NULL;
	line_size = find_line_size(0, map_file);
	if (line_size == -1)
		return (NULL);
	fildes = open(map_file, O_RDONLY);
	if (fildes == -1)	
		return (NULL);
	read_buffer = malloc(sizeof(char) * line_size + 1);
	if (!read_buffer)
	{
		close(fildes);
		return (NULL);
	}
	if (read_buffer_build(read_buffer, fildes, line_size) == -1)
	{
		close(fildes);
		return (NULL);
	}
	close(fildes);
	map_info = (t_map_info)malloc(sizeof(t_map_qual));
	if (!map_info)
		return (NULL);
	if (map_copy_info(read_buffer, map_info) == -1)
		return (NULL); 
	free(read_buffer);
	return (map_info);
}
