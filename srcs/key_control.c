#include "game.h"

void	player_move(const int *array, t_game *game)
{
	game->player->x += array[2];
	game->player->x -= array[0];
	game->player->y += array[1];
	game->player->y -= array[3];
	if (game->player->x < SCALE)
		game->player->x = SCALE;
	else if (game->player->x > game->width - SCALE_X2)
		game->player->x = game->width - SCALE_X2;
	if (game->player->y < SCALE)
		game->player->y = SCALE;
	else if (game->player->y > game->height - SCALE_X2)
		game->player->y = game->height - SCALE_X2;
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
