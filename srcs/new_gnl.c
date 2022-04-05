# include "get_next_line.h"
# include "game.h"

char	*new_gnl(int fd, int line_size, t_map *map)
{
	char	*line;
	ssize_t	line_len;

	line = mem_alloc(sizeof(char) * line_size);
	line_len = read(fd, line, line_size);
	if (line_len - 1 != map->map_width)
		terminate(ERR_MAP_R, map);
	if (line[0] != '1' && line[map->map_width - 1] != '1')
		terminate(ERR_MAP_W, map);
	if (line_len == 0)
		line = ft_free_ptr(line);
	return (line);
}
