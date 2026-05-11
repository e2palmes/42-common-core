#include "../headers/so_long.h"

int	error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
}