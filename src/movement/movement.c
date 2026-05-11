/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:55:41 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:56:23 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_A)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_D)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	next;

	next = game->map[new_y][new_x];
	if (next == '1')
		return ;
	if (next == 'C')
		game->collectibles--;
	if (next == 'E' && game->collectibles == 0)
		close_game(game);
	if (next == 'E')
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}
