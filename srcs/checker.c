#include "game.h"

void	check_extension(int *fd, char *map)
{
	int	len;

	*fd = open(map, O_RDONLY);
	if (*fd == -1)
		terminate(ERR_FILE, NULL);
	len = (int)ft_strlen(map);
	if (len < 5)
		terminate(ERR_LEN, NULL);
	if ((map[len - 4] != '.') && (map[len - 3] != 'b')
		&& (map[len - 2] != 'e') && (map[len - 1] != 'r'))
		terminate(ERR_EXT, NULL);
}

int	check_arg(int argc, char **map)
{
	int	fd;

	if (argc < 2)
		terminate(ERR_ARG0, NULL);
	if (argc > 2)
		terminate(ERR_ARGS, NULL);
	check_extension(&fd, *++map);
	return (fd);
}
