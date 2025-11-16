/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:11 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:13 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_top(t_map *map)
{
	int	x;

	x = 0;
	while (map->array[0][x])
	{
		if (map->array[0][x] != '1')
			ft_exit_error(map, "invalid map wall\n");
		x++;
	}
}

static void	check_sides(t_map *map)
{
	int	y;

	y = 1;
	while (y < map->y - 1)
	{
		if (map->array[y][0] != '1' || map->array[y][map->x - 1] != '1')
			ft_exit_error(map, "invalid map wall\n");
		y++;
	}
}

static void	check_bottom(t_map *map)
{
	int	x;

	x = 0;
	while (map->array[map->y - 1][x])
	{
		if (map->array[map->y - 1][x] != '1')
			ft_exit_error(map, "invalid map wall\n");
		x++;
	}
}

void	checker_wall(t_map *map)
{
	check_top(map);
	check_sides(map);
	check_bottom(map);
}
