#include "game.h"

void	init_file(t_game *game, t_img *img, char *path)
{
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, path,
			&img->width, &img->height);
}

void	img_init(t_game *game)
{
	init_file(game, game->player->player, PLAYER);
}

t_game	*game_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		terminate(ERR_MALLOC, game);
	game->player = (t_player *)malloc(sizeof(t_player));
	game->player->x = 0;
	game->player->y = 0;
	game->player->player = (t_img *)malloc(sizeof(t_img));
	return (game);
}
