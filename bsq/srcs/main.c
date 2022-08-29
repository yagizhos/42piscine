/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:28:41 by dpentlan          #+#    #+#             */
/*   Updated: 2022/08/29 19:19:13 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_load.h"
#include "ft_map_init.h"
#include "ft_map_solve.h"
#include <unistd.h>

void	error_display(void)
{
	write(1, "map error\n", 10);
}

int main(int argc, char **argv)
{
	int	i;	

	i = 1;
	while (i < argc)
	{
		if (map_solve(argv[i]) == -1)
			error_display();
		i++;
	}
	return (0);
}
