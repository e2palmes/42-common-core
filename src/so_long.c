#include "./headers/so_long.h"

int main(int argc, char **argv)
{
    t_game  game;
    char    *map;

    ft_bzero(&game, sizeof(t_game));
    if (argc != 2 || !check_extension(argv[1]))
        return (error("Expected 1 argument\n"));
    map = read_map_file(argv[1]);
    if (!map)
        return (error("could not read the map\n"));
    game.map = ft_split(map, '\n');
    free(map);
    if(!validate_map(&game))
    {
        free_map(game.map);
        return (error("Invalid map"));
    }
    //
    free_map(game.map);
	return (0);
}
