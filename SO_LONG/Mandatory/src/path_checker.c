/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:16:01 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:16:03 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	fill_collectibles(char **tab, int x, int y, t_map *map)
{
	char	type;

	if (x < 0 || x >= map->x || y < 0 || y >= map->y)
		return ;
	if (tab == NULL)
	{
		ft_exit_error(map, "Memory allocation failed\n");
	}
	type = tab[y][x];
	if (type == '1' || type == 'E')
		return ;
	if (type == 'C')
	{
		map->c_check--;
		tab[y][x] = '1';
	}
	tab[y][x] = '1';
	fill_collectibles(tab, x + 1, y, map);
	fill_collectibles(tab, x - 1, y, map);
	fill_collectibles(tab, x, y + 1, map);
	fill_collectibles(tab, x, y - 1, map);
}

static void	fill_exit(char **tab, int x, int y, t_map *map)
{
	char	type;

	if (x < 0 || x >= map->x || y < 0 || y >= map->y)
		return ;
	if (tab == NULL)
	{
		ft_exit_error(map, "Memory allocation failed\n");
	}
	type = tab[y][x];
	if (type == '1')
		return ;
	if (type == 'E')
	{
		map->e_check--;
		tab[y][x] = '1';
		return ;
	}
	tab[y][x] = '1';
	fill_exit(tab, x + 1, y, map);
	fill_exit(tab, x - 1, y, map);
	fill_exit(tab, x, y + 1, map);
	fill_exit(tab, x, y - 1, map);
}

static void	zero_collectibles(char **copy, t_map *map)
{
	int	i;
	int	j;

	if (copy == NULL)
		ft_exit_error(map, "Memory allocation failed\n");
	i = 0;
	while (i < map->y && copy[i] != NULL)
	{
		j = 0;
		while (j < map->x)
		{
			if (copy[i][j] == 'C')
				copy[i][j] = '0';
			j++;
		}
		i++;
	}
}

static void	process_exit(t_map *map)
{
	char	**copy2;

	copy2 = ft_split(map->file, '\n');
	if (!copy2)
		ft_exit_error(map, "Memory allocation failed\n");
	zero_collectibles(copy2, map);
	fill_exit(copy2, map->player.x, map->player.y, map);
	if (map->e_check != 0)
	{
		ft_free_array(copy2, map->y);
		ft_exit_error(map, "invalid exit\n");
	}
	ft_free_array(copy2, map->y);
}

void	check_valid_path(t_map *map)
{
	char	**copy1;

	map->c_check = map->c;
	map->e_check = map->e;
	copy1 = ft_split(map->file, '\n');
	if (!copy1)
		ft_exit_error(map, "Memory allocation failed\n");
	scan_player(map);
	fill_collectibles(copy1, map->player.x, map->player.y, map);
	if (map->c_check != 0)
	{
		ft_free_array(copy1, map->y);
		ft_exit_error(map, "invalid collectible\n");
	}
	ft_free_array(copy1, map->y);
	process_exit(map);
}
