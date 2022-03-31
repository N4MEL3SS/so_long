#include "game.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*line;
	int		fd;

	fd = check_arg(argc, argv);
	line = get_next_line(fd);
	game_init(&game);
	hook(&game);
	return (0);
}
