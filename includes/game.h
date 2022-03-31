#ifndef GAME_H
# define GAME_H

# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror, strerror */
# include <fcntl.h> /* open */
# include <unistd.h> /* read, write, close */

# include "mlx.h"
# include "keycode.h"
# include "events.h"
# include "image.h"
# include "error_msg.h"

# define TRUE 1
# define FALSE 0

# define WIDTH 480
# define HEIGHT 480

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
	t_player	*player;
	t_sprite	*sprite;
}				t_game;

int		check_arg(int argc, char **map_file);
char	*get_next_line(int fd);

void	game_init(t_game *game);

void	hook(t_game *game);

int		key_control_press(int key, t_game *game);
int		key_control_release(int key, t_game *game);

void	player_moving(const int *array, t_player *player);

int		render_loop(t_game *game);

int		close_win(t_game *game);

size_t	ft_strlen(const char *str);
void	terminate(const char *str, void *address);

#endif //GAME_H
