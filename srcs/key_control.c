#include "game.h"

void	wasd_key_array(const int *array, t_player *player)
{
	player->x += array[2];
	player->x -= array[0];
	player->y += array[1];
	player->y -= array[3];
	if (player->x < 0 || player->x > WIDTH)
		player->x = 0;
	if (player->y < 0 || player->y > HEIGHT)
		player->y = 0;
}

int	key_control_press(int key, t_game *game)
{
	if (key == L_SHIFT_KEY && !game->player->shift_flag)
	{
		game->player->step = STEP << 1;
		game->player->shift_flag = 1;
	}
	else if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->player->key_array[key % 10] = game->player->step;
	else if (key == ESC)
		close_win(game);
	return (0);
}

int	key_control_release(int key, t_game *game)
{
	if (key == L_SHIFT_KEY && game->player->shift_flag)
	{
		game->player->step = STEP;
		game->player->shift_flag = 0;
	}
	else if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->player->key_array[key % 10] = 0;
	return (0);
}
