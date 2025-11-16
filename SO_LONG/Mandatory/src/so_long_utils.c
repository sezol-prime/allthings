/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:16:17 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:16:19 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*solong_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
	{
		dup = malloc(1);
		if (!dup)
			return (NULL);
		dup[0] = '\0';
		return (dup);
	}
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = solong_strdup("");
	if (!s2)
		s2 = "";
	if (!s1 || !s2)
		return (free(s1), NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

void	checker_file(t_map *map)
{
	char	*dot;
	size_t	len;

	if (map->filename == NULL)
		ft_exit_error(NULL, "filename must be name.ber\n");
	len = ft_strlen(map->filename);
	if (len < 5)
		ft_exit_error(NULL, "filename must be name.ber\n");
	dot = ft_strrchr(map->filename, '.');
	if (dot == NULL)
		ft_exit_error(NULL, "filename must be name.ber\n");
	if (ft_strncmp(dot, ".ber", 5) != 0)
		ft_exit_error(NULL, "filename must be name.ber\n");
	if (ft_strchr(map->filename, '.') != dot)
		ft_exit_error(NULL, "filename must be name.ber\n");
}

void	scan_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				return ;
			map->player.x++;
		}
		map->player.x = 0;
		map->player.y++;
	}
}
