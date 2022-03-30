#include "game.h"

int	render_loop(t_game *game)
{
	static int	frame = 0;
	static int	x = 1;
	static int	y = 1;
	if (frame % 10 == 0)
	{
		wasd_key_array(game->player->key_array, game->player);
		mlx_clear_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->player->player->img_ptr, PLAYER_X, PLAYER_Y);
		x = game->player->x;
		y = game->player->y;
	}
	else if (frame == 30)
		frame = 0;
	frame++;
	return (0);
}

void	render_control(t_game *game)
{
	mlx_clear_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->player->player->img_ptr, PLAYER_X, PLAYER_Y);
}
