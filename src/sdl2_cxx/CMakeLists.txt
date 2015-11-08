project(sdl2_cxx CXX)

set(SDL2_CXX_VERSION_MAJOR 0)
set(SDL2_CXX_VERSION_MINOR 2)
set(SDL2_CXX_VERSION_PATCH 0)
set(SDL2_CXX_VERSION_STR "${SDL2_CXX_VERSION_MAJOR}.${SDL2_CXX_VERSION_MINOR}.${SDL2_CXX_VERSION_PATCH}")
set(SDL2_CXX_SOVERSION ${SDL2_CXX_VERSION_MAJOR})

set(SDL2_CXX_PUBLIC_HEADERS sdl_init.hpp sdl_error.hpp sdl_dso.hpp sdl_window.hpp sdl_renderer.hpp)
set(SDL2_CXX_SOURCES sdl_init.cpp sdl_error.cpp sdl_dso.cpp sdl_window.cpp sdl_renderer.cpp)

add_library(sdl2_cxx SHARED ${SDL2_CXX_SOURCES})
target_link_libraries(sdl2_cxx ${SDL2_REQUIRED_LIBS})
set_target_properties(sdl2_cxx PROPERTIES
  SOVERSION ${SDL2_CXX_SOVERSION}
  VERSION ${SDL2_CXX_VERSION_STR}
  PUBLIC_HEADER "${SDL2_CXX_PUBLIC_HEADERS}"
)

install(TARGETS sdl2_cxx
  PUBLIC_HEADER DESTINATION include/sdl2_cxx
  LIBRARY DESTINATION lib
)