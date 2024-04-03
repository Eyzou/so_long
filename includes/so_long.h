/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:37:24 by ehamm             #+#    #+#             */
/*   Updated: 2024/03/29 14:53:42 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

# define U 2
# define D 3
# define R 0
# define L 1

# define WALL_PATH "./img/wall.xpm"
# define FLOOR_PATH "./img/grass.xpm"
# define COLL_PATH "./img/carott.xpm"
# define PLAYER_PATH "./img/player.xpm"
# define DOOR_PATH "./img/fish.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		score;
	int		collectible_num;
	int		exit_num;
	int		player_num;
	int		moves;
	int		x;
	int		y;
	int		player[2];
	int		colls_num;
	int		row_num;
	int		player_position;
	char	**map;
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*door_img;
	void	*player_img;
}			t_data;

// Graphics
int			init_map(char *map_path, t_data *game);
void		fill_map(t_data *game, int lines, char *map_path);
void		set_images(t_data *game);
void		print_map(char *line, t_data *game, int index);
void		add_graphics(t_data *game);
void		put_player(t_data *game, int width, int height);

// check map
int			check_rectangle(t_data *game);
void		count_elements(t_data *game);
int			check_map(t_data *game);
int			check_around_map(t_data *game);
void		dfs_matrix(int x, int y, char **map);
int			valid_path(t_data *game);
void		check_p_pos(t_data *game);
void		check_ber(char *argv, t_data *game);

// Moves and key hook
int			key_hook(int keysym, t_data *game);
void		update_player_move(t_data *game, int key);
void		move_top(t_data *game, int i, int j);
void		move_right(t_data *game, int i, int j);
void		move_left(t_data *game, int i, int j);
void		move_down(t_data *game, int i, int j);
void		door_locked_up_down(t_data *game, int door_row, int door_col);
void		door_locked_right_left(t_data *game, int door_row, int door_col);
void		print_foot(int key, t_data *game);

// Closing game
int			close_game(t_data *game);
void		free_map(t_data *game);
void		free_img(t_data *game);
int			error(char *str);

// Define
int			is_up(int key);
int			is_down(int key);
int			is_left(int key);
int			is_right(int key);
int			is_valid(int key);

#endif
