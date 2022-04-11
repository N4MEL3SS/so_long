#include "game.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_game	game;

	map = map_parser(check_arg(--argc, argv), argv);
	game_init(&game, map->map_width, map->map_height);
	game.map = map;
	game.player->x = map->pos_x[P_INDEX];
	game.player->y = map->pos_y[P_INDEX];
	hook(&game);
	return (0);
}
