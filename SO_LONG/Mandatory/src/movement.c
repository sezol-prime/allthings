/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:53 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:55 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_resume(t_map *map, int new_x, int new_y)
{
	char	tile;

	tile = map->array[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
	{
		map->c--;
		map->array[new_y][new_x] = '0';
	}
	if (tile == 'E')
	{
		if (map->c == 0)
			ft_win(map);
		else
			return ;
	}
	map->array[map->player.y][map->player.x] = '0';
	map->player.x = new_x;
	map->player.y = new_y;
	map->array[new_y][new_x] = 'P';
	map->moves++;
	print_movements(map);
	map_printer(map);
}

void	move_up(t_map *map)
{
	move_resume(map, map->player.x, map->player.y - 1);
}

void	move_down(t_map *map)
{
	move_resume(map, map->player.x, map->player.y + 1);
}

void	move_left(t_map *map)
{
	move_resume(map, map->player.x - 1, map->player.y);
}

void	move_right(t_map *map)
{
	move_resume(map, map->player.x + 1, map->player.y);
}
