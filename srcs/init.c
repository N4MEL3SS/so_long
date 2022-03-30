#include "game.h"

t_img	*img_init(void *mlx_ptr, char *path)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		terminate(ERR_MALLOC, img);
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	return (img);
}

t_sprite	*sprite_init(void *mlx_ptr)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		terminate(ERR_MALLOC, sprite);
	sprite->player = img_init(mlx_ptr, PLAYER);
	sprite->background = img_init(mlx_ptr, BACKGROUND);
	sprite->wall = NULL;
	sprite->key = NULL;
	sprite->enemy = NULL;
	return (sprite);
}

void	key_array_init(int *key_array)
{
	int		i;

	i = -1;
	while (++i < KEY_ARR_SIZE)
		key_array[i] = 0;
}

t_player	*player_init(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		terminate(ERR_MALLOC, player);
	player->x = 0;
	player->y = 0;
	player->step = STEP;
	player->shift_flag = 0;
	key_array_init(player->key_array);
	return (player);
}

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		terminate(ERR_MALLOC, game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			WIDTH, HEIGHT, "Game");
	game->player = player_init();
	game->sprite = sprite_init(game->mlx_ptr);
}
