cmake_minimum_required(VERSION 3.21)
project(so_long C)

set(CMAKE_C_STANDARD 99)
#add_compile_options(-DSTRINGPUTX11)

include_directories("includes/")
include_directories("mlx_mac/")

set(HEAD_MLX mlx_mac/mlx.h
		mlx_mac/mlx_int.h
		mlx_mac/mlx_new_window.h
		mlx_mac/mlx_opengl.h
		mlx_mac/mlx_png.h)

set(SRC_MLX mlx_mac/mlx_init_loop.m
		mlx_mac/mlx_int_str_to_wordtab.c
		mlx_mac/mlx_mouse.m
		mlx_mac/mlx_new_image.m
		mlx_mac/mlx_new_window.m
		mlx_mac/mlx_opengl.m
		mlx_mac/mlx_png.c
		mlx_mac/mlx_shaders.c
		mlx_mac/mlx_xpm.c)

set(HEAD_SO_LONG includes/game.h
		includes/error_msg.h
		includes/events.h
		includes/sprite.h
		includes/keycode.h includes/map.h)

set(SRC_LIST srcs/main.c
		srcs/utils1.c
		srcs/close.c
		srcs/key_control.c
		srcs/init.c
		srcs/render.c
		srcs/validator.c
		srcs/checker.c
		srcs/hook.c srcs/get_next_line.c includes/get_next_line.h srcs/get_next_line_utils.c srcs/map_parser.c srcs/map_size.c srcs/utils2.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_library(mlx_mac ${SRC_MLX} ${HEAD_MLX})
target_link_libraries(mlx_mac "-framework OpenGL")
target_link_libraries(mlx_mac "-framework AppKit")

add_executable(so_long ${SRC_LIST} ${HEAD_SO_LONG})
target_link_libraries(so_long ${MLX})
target_link_libraries(so_long "-framework OpenGL")
target_link_libraries(so_long "-framework AppKit")
