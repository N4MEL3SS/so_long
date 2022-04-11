#ifndef GAME_H
# define GAME_H

# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror, strerror */
# include <fcntl.h> /* open */
# include <unistd.h> /* read, write, close */

# include "mlx.h"
# include "map.h"
# include "keycode.h"
# include "events.h"
# include "sprite.h"
# include "error_msg.h"

# define TRUE 1
# define FALSE 0

# define WIDTH 480
# define HEIGHT 480

# define SCALE 32
# define SCALE_X2 64

# define WIDTH_MAX 2560
# define HEIGHT_MAX 1325

# define PLAYER_X game->player->x
# define PLAYER_Y game->player->y
# define SHIFT_FLAG game->player->shift_flag

# define KEY_ARR_SIZE 4
# define STEP 2
# define STEP_RUN 2 * STEP

typedef struct s_player
{
	int		x;
	int		y;
	int		key_array[KEY_ARR_SIZE];
	int		step;
	int		shift_flag;
}				t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_player	*player;
	t_sprite	*sprite;
	int			width;
	int			height;
}				t_game;

int		key_control_press(int key, t_game *game);
int		key_control_release(int key, t_game *game);

void	player_move(const int *array, t_game *game);

void	game_init(t_game *game, int x, int y);

void	hook(t_game *game);

int		render_loop(t_game *game);

int		close_win(t_game *game);

void	ft_error(void);
void	ft_putendl(const char *str);
size_t	ft_strlen(const char *str);

void	*mem_alloc(size_t size);
void	terminate(const char *str, void *address);

#endif //GAME_H
