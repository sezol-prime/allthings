/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:36 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:38 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_img(void *img, char *name, t_map *map)
{
	if (!img)
		ft_exit_error(map, name);
}

static void	file_to_image_check(t_map *map)
{
	check_img(map->img.empty.img, "empty.xpm", map);
	check_img(map->img.wall.img, "wall.xpm", map);
	check_img(map->img.exit.img, "exit.xpm", map);
	check_img(map->img.collectible.img, "collectible.xpm", map);
	check_img(map->img.player.img, "player.xpm", map);
}

static void	load_img(t_map *map, t_tex *tex, char *filename)
{
	tex->img = mlx_xpm_file_to_image(map->mlx, filename, &tex->w, &tex->h);
	check_img(tex->img, filename, map);
}

void	file_to_image(t_map *map)
{
	load_img(map, &map->img.empty, "Resources/empty.xpm");
	load_img(map, &map->img.wall, "Resources/wall.xpm");
	load_img(map, &map->img.exit, "Resources/exit.xpm");
	load_img(map, &map->img.collectible, "Resources/collectible.xpm");
	load_img(map, &map->img.player, "Resources/player.xpm");
	file_to_image_check(map);
}
