/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:18 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:20 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_tex(t_tex *tex)
{
	tex->img = NULL;
	tex->w = 0;
	tex->h = 0;
}

static void	init_img_values(t_map *map)
{
	init_tex(&map->img.empty);
	init_tex(&map->img.wall);
	init_tex(&map->img.exit);
	init_tex(&map->img.collectible);
	init_tex(&map->img.player);
}

void	map_initializer(t_map *map, char **av)
{
	ft_bzero(map, sizeof(t_map));
	map->filename = av[1];
	init_img_values(map);
}
