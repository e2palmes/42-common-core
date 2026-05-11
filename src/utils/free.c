/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:43:38 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:45:47 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
		destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	game->map = NULL;
}
