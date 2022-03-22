#include "game.h"

int	render_loop(t_game *game)
{
	static int	frame = 0;
	static int	x = 1;
	static int	y = 0;

	if (frame < 50 && (x != game->player->x || y != game->player->y))
	{
		mlx_clear_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->player->player->img_ptr,
			game->player->x, game->player->y);
		x = game->player->x;
		y = game->player->y;
		PLAYER_X++;
		PLAYER_Y++;
	}
	else if (frame == 100)
		frame = 0;
	frame += 2;
	return (0);
}
