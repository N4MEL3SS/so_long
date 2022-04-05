#include "game.h"

void	player_moving(const int *array, t_player *player)
{
	player->x += array[2];
	player->x -= array[0];
	player->y += array[1];
	player->y -= array[3];
	if (player->x < 0)
		player->x = 0;
	else if (player->x > WIDTH - 32)
		player->x = WIDTH - 32;
	if (player->y < 0)
		player->y = 0;
	else if (player->y > HEIGHT - 32)
		player->y = HEIGHT - 32;
}

int	key_control_press(int key, t_game *game)
{
	if (key == L_SHIFT_KEY && !SHIFT_FLAG++)
		game->player->step = STEP_RUN;
	else if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->player->key_array[key % 10] = game->player->step;
	else if (key == ESC)
		close_win(game);
	return (0);
}

int	key_control_release(int key, t_game *game)
{
	if (key == L_SHIFT_KEY && SHIFT_FLAG--)
		game->player->step = STEP;
	else if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->player->key_array[key % 10] = 0;
	return (0);
}
