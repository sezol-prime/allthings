/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:16:08 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:16:10 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	expose_hook(void *param)
{
	map_printer((t_map *)param);
	return (0);
}

static void	init_graphics_or_exit(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		ft_exit_error(map, "failed to initialize mlx\n");
	map->wnd = mlx_new_window(map->mlx, map->x * IMG_PXL, map->y * IMG_PXL,
			WND_NAME);
	if (!map->wnd)
		ft_exit_error(map, "failed to create window\n");
}

void	run_so_long(t_map *map, char **av)
{
	map_initializer(map, av);
	map_array(map);
	map_checker(map);
	init_graphics_or_exit(map);
	file_to_image(map);
	map_printer(map);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		ft_exit_error(NULL, "Missing filename\n");
	map.filename = av[1];
	checker_file(&map);
	run_so_long(&map, av);
	mlx_hook(map.wnd, 17, 0, ft_close, &map);
	mlx_key_hook(map.wnd, key_hook, &map);
	mlx_hook(map.wnd, 12, 1L << 15, expose_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
