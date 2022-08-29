/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:27:36 by dpentlan          #+#    #+#             */
/*   Updated: 2022/08/29 17:27:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_INIT_H
# define FT_MAP_INIT_H

typedef struct s_map_qual t_map_qual;

struct s_map_qual {
	int		height;
	char	space;
	char	obs;
	char	fill;
};

typedef	t_map_qual* t_map_info;


int	map_num_copy(char *read_buffer, t_map_info map_info);
int	map_copy_info(char *read_buffer, t_map_info map_info);
int	read_buffer_build(char *read_buffer, int fildes, int line_size);
t_map_info	map_init(char *map_file);

#endif

