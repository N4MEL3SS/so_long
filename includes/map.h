#ifndef MAP_H
# define MAP_H

# include "get_next_line.h"

# define ARR_SIZE 64

# define EMPTY 0
# define WALL 1
# define COLLECT 19
# define EXIT_MAP 21
# define PLAYER_START 32

typedef struct s_map
{
	int		map_height;
	int		map_width;
	int		map[ARR_SIZE][ARR_SIZE];
}				t_map;

int		check_arg(int argc, char **map_file);

t_map	*map_parser(int fd);
char	*new_gnl(int fd, int line_size, t_map *map);

#endif //MAP_H
