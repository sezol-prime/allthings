/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:26 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:28 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_centered(t_map *m, t_tex *t, int px, int py)
{
	int	off_x;
	int	off_y;

	off_x = (IMG_PXL - t->w) / 2;
	off_y = (IMG_PXL - t->h) / 2;
	mlx_put_image_to_window(m->mlx, m->wnd, t->img, px + off_x, py + off_y);
}

static void	map_type(t_map *map, int px, int py)
{
	char	tile;

	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty.img, px, py);
	tile = map->array[py / IMG_PXL][px / IMG_PXL];
	if (tile == '1')
		put_centered(map, &map->img.wall, px, py);
	else if (tile == 'C')
		put_centered(map, &map->img.collectible, px, py);
	else if (tile == 'E')
		put_centered(map, &map->img.exit, px, py);
	else if (tile == 'P')
		put_centered(map, &map->img.player, px, py);
}

void	map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(map->mlx, map->wnd);
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}
