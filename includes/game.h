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
# define HEIGHT 320

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	int		x;
	int		y;
	t_img	*player;
}				t_player;

typedef struct s_game
{
	t_player	*player;
	t_mlx		*mlx;
}				t_game;

t_game	*game_init(void);
void	img_init(t_game *game);

int		key_control(int key, t_game *game);

int		render_loop(t_game *game);

int		close_win(t_mlx *game);
int		close_esc(int keycode, t_mlx *game);

void	terminate(const char *str, void *address);

#endif //GAME_H
