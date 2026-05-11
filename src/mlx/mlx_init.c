/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:57:34 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:57:40 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error("MLX init failed"));
	game->win = mlx_new_window(game->mlx, game->width * 32,
			game->height * 32, "so_long");
	if (!game->win)
		return (error("Window creation failed"));
	return (1);
}
