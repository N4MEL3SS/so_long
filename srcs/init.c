#include "game.h"

t_img	*img_init(void *mlx_ptr, char *path)
{
	t_img	*img;

	img = (t_img *)mem_alloc(sizeof(t_img));
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	return (img);
}

t_sprite	*sprite_init(void *mlx_ptr)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)mem_alloc(sizeof(t_sprite));
	sprite->static_img[0] = img_init(mlx_ptr, BACKG_PATH);
	sprite->static_img[1] = img_init(mlx_ptr, WALL_PATH);
	sprite->collect_img = img_init(mlx_ptr, COLLECT_PATH);
	sprite->exit_img = img_init(mlx_ptr, EXIT_PATH);
	sprite->player_img = img_init(mlx_ptr, PLAYER_PATH);
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

	player = (t_player *)mem_alloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->step = STEP;
	player->shift_flag = 0;
	key_array_init(player->key_array);
	return (player);
}

void	game_init(t_game *game, int x, int y)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		terminate(ERR_MALLOC, game->mlx_ptr);
	game->width = x * SCALE;
	game->height = y * SCALE;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
		game->width, game->height, "Game");
	game->player = player_init();
	game->sprite = sprite_init(game->mlx_ptr);
}
