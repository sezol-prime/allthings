/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:14:14 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:14:17 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_textures(t_map *map)
{
	if (map->img.empty.img)
		mlx_destroy_image(map->mlx, map->img.empty.img);
	if (map->img.wall.img)
		mlx_destroy_image(map->mlx, map->img.wall.img);
	if (map->img.exit.img)
		mlx_destroy_image(map->mlx, map->img.exit.img);
	if (map->img.collectible.img)
		mlx_destroy_image(map->mlx, map->img.collectible.img);
	if (map->img.player.img)
		mlx_destroy_image(map->mlx, map->img.player.img);
}

static void	free_window(t_map *map)
{
	if (map->wnd)
		mlx_destroy_window(map->mlx, map->wnd);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}

static void	free_map_data(t_map *map)
{
	if (map->array)
	{
		ft_free_array(map->array, ft_array_len(map->array));
		map->array = NULL;
	}
	if (map->copy)
	{
		ft_free_array(map->copy, ft_array_len(map->copy));
		map->copy = NULL;
	}
	if (map->file)
	{
		free(map->file);
		map->file = NULL;
	}
	if (map->line)
	{
		free(map->line);
		map->line = NULL;
	}
}

void	free_all(t_map *map)
{
	if (!map)
		return ;
	free_textures(map);
	free_window(map);
	free_map_data(map);
}
