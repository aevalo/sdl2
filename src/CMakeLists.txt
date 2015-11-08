project(sdl2_test C CXX)

include_directories(sdl2_cxx sdl2_image_cxx)

add_subdirectory(sdl2_cxx)
add_subdirectory(sdl2_image_cxx)

add_executable(sdl2_test main.c)
target_link_libraries(sdl2_test ${SDL2_REQUIRED_LIBS})

add_executable(sdl2_test_cxx main.cpp zlib_dso.cpp bzip2_dso.cpp)
target_link_libraries(sdl2_test_cxx ${SDL2_REQUIRED_LIBS} sdl2_cxx sdl2_image_cxx)
add_dependencies(sdl2_test_cxx sdl2_cxx sdl2_image_cxx)

install(TARGETS sdl2_test sdl2_test_cxx DESTINATION bin)