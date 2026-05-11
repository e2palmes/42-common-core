/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:58:57 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:58:58 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../includes/ft_printf/ft_printf.h"
# include "../../includes/getnextline/get_next_line.h"
# include <fcntl.h>
# include "../../includes/ft_printf/libft/libft.h"
# include "../../includes/minilibx-linux/mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;

	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;

	char	**map;

	int		width;
	int		height;

	int		player_x;
	int		player_y;

	int		players;
	int		exits;
	int		collectibles;
	int		moves;
}	t_game;

/* parsing */
int		check_extension(char *file);
char	*read_map_file(char *path);
int		check_path(t_game *game);

/* validation */
int		validate_map(t_game *game);
int		is_rectangular(char **map);
int		check_walls(t_game *game);
int		check_components(t_game *game);

/* utils */
int		map_height(char **map);
int		check_extension(char *file);

/* Free */
int		error(char *msg);
void	free_map(char **map);
void	free_game(t_game *game);

/* Mlx */
int		init_mlx(t_game *game);
int		close_game(t_game *game);

/* Textures */
int		load_textures(t_game *game);
void	render_map(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
void	put_texture(t_game *game, void *img, int x, int y);

/* Movement*/
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

#endif
