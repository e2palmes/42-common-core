/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:53:33 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/11 23:54:01 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*read_map_file(char *path)
{
	int		fd;
	char	*line;
	char	*all;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = all;
		all = ft_strjoin(all, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (all);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_remaining_items(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static char	**copy_map(char **map)
{
	char	**copy;
	int		height;
	int		i;

	height = map_height(map);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_path(t_game *game)
{
	char	**copy;

	copy = copy_map(game->map);
	if (!copy)
		return (0);
	flood_fill(copy, game->player_x, game->player_y);
	if (!check_remaining_items(copy))
	{
		free_map(copy);
		return (0);
	}
	free_map(copy);
	return (1);
}
