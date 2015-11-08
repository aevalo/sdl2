cmake_minimum_required(VERSION 3.3)
project(sdl2 C)

find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})
add_definitions(${SDL2_CFLAGS_OTHER})

set(SDL2_REQUIRED_LIBS ${SDL2_LIBRARIES})

add_subdirectory(src)
