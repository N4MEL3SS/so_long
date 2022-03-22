#include "game.h"

int	close_win(t_mlx *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}

int	close_esc(int keycode, t_mlx *game)
{
	if (keycode == ESC)
		close_win(game);
	return (EXIT_SUCCESS);
}
