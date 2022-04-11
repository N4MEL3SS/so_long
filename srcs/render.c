#include "game.h"

void	background(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map->map_height)
	{
		j = -1;
		while (++j < game->map->map_width)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->sprite->static_img[game->map->map[i][j]]->img_ptr,
				j * SCALE, i * SCALE);
		}
	}
}

int	render_loop(t_game *game)
{
	static int	frame = 0;

	if (frame % 5 == 0)
	{
		player_move(game->player->key_array, game);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		background(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->exit_img->img_ptr,
			game->map->pos_x[E_INDEX], game->map->pos_y[E_INDEX]);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->collect_img->img_ptr,
			game->map->pos_x[C_INDEX], game->map->pos_y[C_INDEX]);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->player_img->img_ptr, PLAYER_X, PLAYER_Y);
	}
	if (frame == 60)
		frame = 0;
	frame++;
	return (0);
}
