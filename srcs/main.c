#include "game.h"

int	main(void)
{
	t_mlx	mlx;
	t_game	*game;

	game = game_init();
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		terminate(ERR_MALLOC, mlx.mlx_ptr);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Game");
	game->mlx = &mlx;
	img_init(game);
	key_array_init(game->player->key_array);
	mlx_hook(mlx.win_ptr, KEY_PRESS, 1L << 0, key_control_press, game);
	mlx_hook(mlx.win_ptr, KEY_RELEASE, 1L << 1, key_control_release, game);
	mlx_hook(mlx.win_ptr, DESTROY, 0, close_win, &mlx);
	mlx_loop_hook(game->mlx->mlx_ptr, render_loop, game);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
