#include "game.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

void	ft_putendl(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	terminate(const char *str, void *address)
{
	free(address);
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
