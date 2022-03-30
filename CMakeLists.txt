cmake_minimum_required(VERSION 3.21)
project(so_long C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
include_directories("mlx_mac/")

set(HEAD_LIST includes/game.h
		includes/error_msg.h
		includes/events.h
		includes/image.h
		includes/keycode.h)

set(SRC_LIST srcs/main.c
		srcs/utils.c
		srcs/close.c
		srcs/key_control.c
		srcs/init.c
		srcs/render.c
		srcs/validator.c
		srcs/checker.c
		srcs/hook.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(so_long ${SRC_LIST} ${HEAD_LIST})
target_link_libraries(so_long ${MLX})
target_link_libraries(so_long "-framework OpenGL")
target_link_libraries(so_long "-framework AppKit")
