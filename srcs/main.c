#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	map_parser(check_arg(argc, argv));
	game_init(&game);
	hook(&game);
	return (0);
}
