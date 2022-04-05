#include "game.h"

void	map_fline(int fd, t_map *map)
{
	char	buff;
	int		len;
	int		wall_len;

	len = 0;
	wall_len = 0;
	read(fd, &buff, 1);
	while (buff && buff != '\n')
	{
		map->map[0][len] = (int)buff - 48;
		wall_len += map->map[0][len];
		len++;
		read(fd, &buff, 1);
	}
	if (len != wall_len)
		terminate(ERR_MAP_W, map);
	map->map_width = len;
}

int	map_mid(int fd, t_map *map, int row)
{
	char	*line;
	int		i;

	i = -1;
	line = new_gnl(fd, map->map_width + 1, map);
	if (!line)
		return (0);
	while (line[++i] != '\n')
		map->map[row][i] = (int)line[i] - 48;
	line = ft_free_ptr(line);
	return (1);
}

t_map	*map_parser(int fd)
{
	t_map	*map;
	int		row;

	row = 1;
	map = (t_map *)mem_alloc(sizeof(t_map));
	map_fline(fd, map);
	while (map_mid(fd, map, row))
		row++;
	map->map_height = row;
	return (map);
}
