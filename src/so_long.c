/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:40:23 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:42:33 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/so_long.h"

int	init_map(t_game *game, int argc, char **argv)
{
	char	*raw_map;

	if (argc != 2 || !check_extension(argv[1]))
		return (error("Invalid arguments"));
	raw_map = read_map_file(argv[1]);
	if (!raw_map)
		return (error("Could not read map"));
	game->map = ft_split(raw_map, '\n');
	free(raw_map);
	if (!game->map)
		return (error("Map split failed"));
	if (!validate_map(game))
	{
		free_game(game);
		return (error("Invalid map"));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!init_map(&game, argc, argv))
		return (1);
	if (!init_mlx(&game))
	{
		free_game(&game);
		return (1);
	}
	mlx_hook(game.win, 17, 0, close_game, &game);
	if (!load_textures(&game))
		return (free_game(&game), 1);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
