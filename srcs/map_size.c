#include "game.h"

int	map_first_line(int fd, t_map *map)
{
	ssize_t		len;
	char		c;

	len = 0;
	c = '1';
	while (c && c != '\n')
	{
		if (c != '1')
			terminate(ERR_MAP_W, map);
		len += read(fd, &c, 1);
	}
	return ((int)--len);
}

int	map_all_line(int fd, int size)
{
	char	*map_line;
	int		line_count;

	line_count = 1;
	map_line = get_next_line(fd, size);
	while (map_line != NULL && ++line_count)
	{
		free(map_line);
		map_line = get_next_line(fd, size);
	}
	return (line_count);
}

void	map_size(int fd, t_map *map)
{
	map->map_width = map_first_line(fd, map);
	map->map_height = map_all_line(fd, map->map_width + 1);
	close(fd);
}
