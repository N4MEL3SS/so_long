#include "game.h"

int	*map_arr_write(int fd, int size, int y, t_map *map)
{
	int		i;
	int		*line_arr;
	char	*line;

	i = 0;
	line_arr = mem_alloc(sizeof(int) * size);
	line = get_next_line(fd, size + 1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'P' || line[i] == 'E' || line[i] == 'C')
		{
			map->pos_x[(int)((line[i] - 67) % 10)] = i * SCALE;
			map->pos_y[(int)((line[i] - 67) % 10)] = y * SCALE;
			line_arr[i] = 0;
		}
		else
			line_arr[i] = (int)(line[i] - 48);
		printf("%d", line_arr[i]);
		i++;
	}
	printf("\n");
	if (i != size)
		terminate(ERR_MAP_R, line_arr);
	return (line_arr);
}

t_map	*map_parser(int fd, char **map_path)
{
	t_map	*map;
	int		j;

	j = -1;
	map = (t_map *)mem_alloc(sizeof(t_map));
	map_size(fd, map);
	fd = open(*++map_path, O_RDONLY);
	map->map = mem_alloc(sizeof(int *) * (map->map_height + 1));
	while (++j < map->map_height)
		map->map[j] = map_arr_write(fd, map->map_width, j, map);
	map->map[j] = NULL;
	close(fd);
	return (map);
}
