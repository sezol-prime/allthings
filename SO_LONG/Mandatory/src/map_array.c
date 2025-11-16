/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:14:23 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:14:26 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_rem(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

static void	process_line(int fd, t_map *map)
{
	if (!map->line)
	{
		if (map->y == 0)
			ft_exit_error(map, "empty map file\n");
		return ;
	}
	if (map->line[0] == '\n')
	{
		free(map->line);
		map->line = NULL;
		free_rem(fd);
		ft_exit_error(map, "empty line detected in map\n");
	}
	map->file = ft_strjoinfree(map->file, map->line);
	if (!map->file)
	{
		free_rem(fd);
		ft_exit_error(map, "memory allocation failed\n");
	}
	map->y++;
}

static char	*read_map(int fd, t_map *map)
{
	map->line = get_next_line(fd);
	while (map->line)
	{
		process_line(fd, map);
		free(map->line);
		map->line = get_next_line(fd);
	}
	free_rem(fd);
	return (map->file);
}

void	map_array(t_map *map)
{
	int	fd;

	map->y = 0;
	map->line = NULL;
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error(map, "failed to open file\n");
	map->file = read_map(fd, map);
	close(fd);
	map->array = ft_split(map->file, '\n');
	if (!map->array)
		ft_exit_error(map, "Empty map or memory allocation failed\n");
	map->x = ft_strlen(map->array[0]);
}
