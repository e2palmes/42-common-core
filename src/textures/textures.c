/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:58:08 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:58:10 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	put_texture(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx,
		game->win, img, x * 32, y * 32);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		put_texture(game, game->wall, x, y);
	else if (tile == '0')
		put_texture(game, game->floor, x, y);
	else if (tile == 'P')
		put_texture(game, game->player, x, y);
	else if (tile == 'C')
		put_texture(game, game->collectible, x, y);
	else if (tile == 'E')
		put_texture(game, game->exit, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	load_textures(t_game *game)
{
	int	size;

	size = 32;
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &size, &size);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &size, &size);
	if (!game->wall)
		return (error("wall.xpm failed"));
	if (!game->floor)
		return (error("floor.xpm failed"));
	if (!game->player)
		return (error("player.xpm failed"));
	if (!game->collectible)
		return (error("collectible.xpm failed"));
	if (!game->exit)
		return (error("exit.xpm failed"));
	return (1);
}
