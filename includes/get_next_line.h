#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*buff_str_init(void);
void	*ft_free_ptr(void *ptr);
int		ft_str_chr(char *str, ssize_t *len);
void	ft_str_cpy(char *str, ssize_t line_len);
char	*ft_str_join(char *dst, char *src, ssize_t line_len);

#endif //GET_NEXT_LINE_H
