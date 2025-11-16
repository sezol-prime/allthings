/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:03 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:05 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	scan_cells(t_map *map)
{
	int		y;
	int		x;
	char	cell;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			cell = map->array[y][x];
			if (cell == 'C')
				map->c++;
			else if (cell == 'E')
				map->e++;
			else if (cell == 'P')
				map->p++;
			else if (cell != '0' && cell != '1')
				ft_exit_error(map, "invalid map elements\n");
			x++;
		}
		y++;
	}
}

static void	validate_counts(t_map *map)
{
	if (map->c < 1 || map->e != 1 || map->p != 1)
	{
		ft_exit_error(map, "invalid map elements\n");
	}
}

void	checker_params(t_map *map)
{
	map->c = 0;
	map->e = 0;
	map->p = 0;
	scan_cells(map);
	validate_counts(map);
}
