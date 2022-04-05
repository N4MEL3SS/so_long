#include "get_next_line.h"

char	*get_read_file(int fd, char *buff_str, int buff_size)
{
	char		*line_str;
	ssize_t		line_len;
	ssize_t		buff_len;
	ssize_t		full_len;

	full_len = 0;
	line_str = NULL;
	if (!ft_str_chr(buff_str, &line_len))
	{
		buff_len = 1;
		while (buff_len > 0 && !ft_str_chr(buff_str, &line_len))
		{
			full_len += line_len;
			line_str = ft_str_join(line_str, buff_str, full_len);
			buff_len = read(fd, buff_str, buff_size);
			if (!line_str || buff_len == -1)
				return (NULL);
			*(buff_str + buff_len) = '\0';
		}
	}
	line_str = ft_str_join(line_str, buff_str, full_len + line_len);
	ft_str_cpy(buff_str, line_len);
	return (line_str);
}

char	*get_next_line(int fd, int buff_size)
{
	static char		*buff_str;
	char			*line_str;
	char			check;

	if (fd < 0 || read(fd, &check, 0) == -1)
		return (NULL);
	if (!buff_str)
		buff_str = buff_str_init(buff_size);
	line_str = get_read_file(fd, buff_str, buff_size);
	if (line_str == NULL || *line_str == '\0')
	{
		buff_str = ft_free_ptr(buff_str);
		line_str = ft_free_ptr(line_str);
	}
	return (line_str);
}
