/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:14:04 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:14:07 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close(t_map *map)
{
	free_all(map);
	exit(EXIT_SUCCESS);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	write(1, "\nYOU WON\n", 10);
	ft_close(map);
}

void	ft_exit_error(t_map *map, const char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
		ft_putstr_fd((char *)msg, 2);
	if (map)
		free_all(map);
	exit(EXIT_FAILURE);
}
