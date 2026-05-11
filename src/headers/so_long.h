#ifndef SO_LONG_H
# define SO_LONG_H

#include "../../includes/ft_printf/ft_printf.h"
#include "../../includes/getnextline/get_next_line.h"
#include <fcntl.h>
#include "../../includes/ft_printf/libft/libft.h"
#include "../../includes/minilibx-linux/mlx.h"

typedef struct s_game
{
	int		player_x;
	int		player_y;
	int		players;
	int		exits;
	int		collectibles;
	int		width;
	int		height;
	char	**map;
}	t_game;

/* parsing */
int		check_extension(char *file);
char	*read_map_file(char *path);

/* validation */
int		validate_map(t_game *game);
int		is_rectangular(char **map);
int		check_walls(t_game *game);
int		check_components(t_game *game);

/* utils */
int		map_height(char **map);
int		check_extension(char *file);

/* Errors */
int		error(char *msg);
void	free_map(char **map);
void	free_game(t_game *game);

#endif