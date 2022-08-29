/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_load.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:35:21 by dpentlan          #+#    #+#             */
/*   Updated: 2022/08/29 19:17:05 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_LOAD_H
# define FT_MAP_LOAD_H
# include "ft_map_init.h"
# include "ft_map_load.h"

int skip_to(int line, int file_desc);
int find_line_size(int line, char *file);
char    **map_load(char *file, t_map_info map_info);


#endif
