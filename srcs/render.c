#include "game.h"

int	render_loop(t_game *game)
{
	static int	frame = 0;

	if (frame < 30)
	{
		wasd_key_array(game->player->key_array, game->player);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->background->img_ptr, 0, 0);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->player->img_ptr, PLAYER_X, PLAYER_Y);
	}
	else if (frame == 30)
		frame = 0;
	frame++;
	return (0);
}
