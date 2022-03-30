cmake_minimum_required(VERSION 3.21)
project(so_long C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
include_directories("mlx_mac/")
set(SRC_LIST includes/game.h includes/error_msg.h srcs/main.c includes/image.h includes/keycode.h includes/events.h srcs/utils.c srcs/close.c srcs/key_control.c srcs/init.c srcs/render.c srcs/validator.c srcs/checker.c)
set(SRC_MLX mlx_mac/mlx_new_window.m)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(so_long ${SRC_LIST} ${SRC_MLX})
target_link_libraries(so_long ${MLX})
target_link_libraries(so_long "-framework OpenGL")
target_link_libraries(so_long "-framework AppKit")
