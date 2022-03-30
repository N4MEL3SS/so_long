#ifndef IMAGE_H
# define IMAGE_H

# define PLAYER "/Users/celadia/school21/so_long/img/player.xpm"
# define BACKGROUND "/Users/celadia/school21/so_long/img/background.xpm"

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct s_sprite
{
	t_img	*wall;
	t_img	*background;
	t_img	*key;
	t_img	*player;
	t_img	*enemy;
}				t_sprite;

#endif //IMAGE_H
