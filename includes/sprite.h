#ifndef IMAGE_H
# define IMAGE_H

# define PLAYER_PATH "/Users/celadia/school21/so_long/img/player.xpm"
# define BACKG_PATH "/Users/celadia/school21/so_long/img/background.xpm"
# define COLLECT_PATH "/Users/celadia/school21/so_long/img/key0.XPM"
# define WALL_PATH "/Users/celadia/school21/so_long/img/wall.xpm"
# define EXIT_PATH "/Users/celadia/school21/so_long/img/close_door.xpm"

# define B_INDEX 0
# define W_INDEX 1

# define C_INDEX 0
# define E_INDEX 2
# define P_INDEX 3

# define IMG_ARR_SIZE 2

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct s_sprite
{
	t_img	*static_img[IMG_ARR_SIZE];
	t_img	*player_img;
	t_img	*collect_img;
	t_img	*exit_img;
}				t_sprite;

#endif //IMAGE_H
