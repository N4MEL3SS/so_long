#include "game.h"

void	wasd_key(int key, t_player *player)
{
	if (key == W_KEY)
		player->y -= 32;
	else if (key == A_KEY)
		player->x -= 32;
	else if (key == S_KEY)
		player->y += 32;
	else if (key == D_KEY)
		player->x += 32;
}

int	key_control(int key, t_game *game)
{
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		wasd_key(key, game->player);
	else if (key == ESC)
		close_win(game->mlx);
	return (0);
}
