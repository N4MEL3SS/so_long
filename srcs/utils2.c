#include "game.h"

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
	ft_error();
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
