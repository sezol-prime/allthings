/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:12:55 by sitao             #+#    #+#             */
/*   Updated: 2025/05/31 12:13:54 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

/*=== Keycodes ===*/
# define IMG_PXL 50
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362
# define ESC 65307
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define WND_NAME "so_long"

/*=== Structs ===*/
typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_tex
{
	void		*img;
	int			w;
	int			h;
}				t_tex;

typedef struct s_img
{
	t_tex		empty;
	t_tex		wall;
	t_tex		exit;
	t_tex		collectible;
	t_tex		player;
}				t_img;

typedef struct s_map
{
	int			fd;
	char		**array;
	char		**copy;
	char		*file;
	char		*line;
	char		*filename;
	int			x;
	int			y;
	int			c;
	int			e;
	int			p;
	int			exit;
	int			moves;
	int			c_check;
	int			e_check;
	void		*mlx;
	void		*wnd;
	t_player	player;
	t_img		img;
}				t_map;

/*=== creat and check map ===*/
void			map_initializer(t_map *map, char **av);
void			map_checker(t_map *map);
void			map_array(t_map *map);
void			map_printer(t_map *map);
void			file_to_image(t_map *map);
void			file_to_image_player(t_map *map);
void			checker_params(t_map *map);
void			checker_wall(t_map *map);
void			checker_size(t_map *map);

/*=== check path ===*/
void			check_valid_path(t_map *map);
void			scan_player(t_map *map);

/* === Movement ===*/
void			move_up(t_map *map);
void			move_down(t_map *map);
void			move_left(t_map *map);
void			move_right(t_map *map);
int				key_hook(int keycode, t_map *map);
void			print_movements(t_map *map);

/*=== Exit & Win ===*/
int				ft_close(t_map *map);
void			ft_win(t_map *map);
void			ft_exit_error(t_map *map, const char *msg);
void			free_all(t_map *map);

/* === Tools === */
int				ft_free_array(char **ret, int count);
char			*ft_strjoinfree(char *s1, char *s2);
char			*solong_strdup(const char *s);
int				ft_array_len(char **array);
void			checker_file(t_map *map);

#endif
