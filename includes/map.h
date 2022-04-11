#ifndef MAP_H
# define MAP_H

# include "get_next_line.h"

# define EMPTY 0
# define WALL 1
# define COLLECT 19
# define EXIT_MAP 21
# define PLAYER_START 32

# define POS_ARR_SIZE 4

typedef struct s_map
{
	int		map_height;
	int		map_width;
	int		**map;
	int		pos_x[POS_ARR_SIZE];
	int		pos_y[POS_ARR_SIZE];
}				t_map;

t_map	*map_parser(int fd, char **map_path);

int		check_arg(int argc, char **map_file);

void	map_size(int fd, t_map *map);

#endif //MAP_H
