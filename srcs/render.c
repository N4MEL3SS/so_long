#include "game.h"

int	render_loop(t_game *game)
{
	static int	frame = 0;

	if (frame % 5 == 0)
	{
		player_moving(game->player->key_array, game->player);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->player->img_ptr, PLAYER_X, PLAYER_Y);
	}
	if (frame == 60)
		frame = 0;
	frame++;
	return (0);
}
