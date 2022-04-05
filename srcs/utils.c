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
	write(1, RED, COLOR_SIZE);
	write(1, "Error\n", 6);
	write(1, COLOR_END, COLOR_SIZE);
	write(1, GREEN, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}

void	*mem_alloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		terminate(ERR_MALLOC, ptr);
	return (ptr);
}

void	terminate(const char *str, void *address)
{
	free(address);
	address = NULL;
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
