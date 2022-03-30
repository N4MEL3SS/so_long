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

void	key_array(int i, t_player *player)
{
	player->key_array[i] = player->step;
}

int	key_control_press(int key, t_game *game)
{
	if (key == L_SHIFT_KEY && !game->player->shift_flag)
	{
		game->player->step = 2 * STEP;
		game->player->shift_flag = 1;
	}
	if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		key_array(key % 10, game->player);
	else if (key == ESC)
		close_win(game->mlx);
	return (0);
}

void	key_array_clear(int key, t_player *player)
{
	player->key_array[key] = 0;
}

int	key_control_release(int key, t_game *game)
{
	if (key == L_SHIFT_KEY && game->player->shift_flag)
	{
		game->player->step = STEP;
		game->player->shift_flag = 0;
	}
	if (key == L_SHIFT_KEY)
		game->player->step = STEP;
	if (key == A_KEY || key == D_KEY || key == S_KEY)
		key_array_clear(key, game->player);
	else if (key == W_KEY)
		key_array_clear(3, game->player);
	return (0);
}
