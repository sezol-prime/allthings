/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:44 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:15:46 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	if (keycode == LEFT || keycode == KEY_A)
		move_left(map);
	else if (keycode == DOWN || keycode == KEY_S)
		move_down(map);
	else if (keycode == RIGHT || keycode == KEY_D)
		move_right(map);
	else if (keycode == UP || keycode == KEY_W)
		move_up(map);
	return (0);
}

void	print_movements(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r\033[K", 5);
	write(1, move, ft_strlen(move));
	write(1, "moves", 5);
	free(move);
}
