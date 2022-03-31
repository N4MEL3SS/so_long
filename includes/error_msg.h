#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERR_MALLOC "Memory not allocated."
# define ERR_ARG0 	"You must specify the path to the map."
# define ERR_ARGS 	"Only 1 argument is allowed."
# define ERR_FILE 	"File reading error."
# define ERR_EXT	"Invalid extension. The map must be in the format '*.ber'"
# define ERR_LEN	"The file is not recognized"

/* Foreground colors */
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define COLOR_END "\e[0;39m"
# define COLOR_SIZE 7

#endif //ERROR_MSG_H
