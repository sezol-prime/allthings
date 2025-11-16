/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:14:50 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:14:53 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	checker_params(t_map *map);
void	checker_wall(t_map *map);

void	checker_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	max = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (max != x)
			ft_exit_error(map, "map is not rectangular\n");
		y++;
	}
	map->x = max;
}

void	check_empty_lines(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
	{
		if (map->array[i][0] == '\0')
			ft_exit_error(map, "empty line detected in map\n");
		i++;
	}
}

void	map_checker(t_map *map)
{
	checker_size(map);
	check_empty_lines(map);
	checker_wall(map);
	checker_params(map);
	check_valid_path(map);
	ft_free_array(map->copy, ft_array_len(map->copy));
	map->copy = NULL;
}
