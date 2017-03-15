cmake_minimum_required(VERSION 3.6)
project(fdf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES fdf.c fdf.h ft_readmap.c ft_valid.c ft_draw.c ft_isometric.c)

add_executable(fdf ${SOURCE_FILES})
target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)