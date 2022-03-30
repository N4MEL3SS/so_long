#include "game.h"

int	main(void)
{
	t_game	game;

	game_init(&game);
	hook(&game);
	return (0);
}
