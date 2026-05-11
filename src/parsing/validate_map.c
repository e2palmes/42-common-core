/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:54:58 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:55:04 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	validate_map(t_game *game)
{
	if (!game->map || !game->map[0])
		return (0);
	game->height = map_height(game->map);
	game->width = ft_strlen(game->map[0]);
	if (!is_rectangular(game->map))
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_components(game))
		return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (!ft_strchr("01PEC", tile))
		return (0);
	if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->players++;
	}
	else if (tile == 'E')
		game->exits++;
	else if (tile == 'C')
		game->collectibles++;
	return (1);
}

int	check_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!check_tile(game, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (game->players == 1
		&& game->exits == 1
		&& game->collectibles >= 1);
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1'
			|| game->map[game->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1'
			|| game->map[y][game->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
