#include <SDL.h>
#include "sdl_error.hpp"

namespace sdl2
{
  sdl_error::sdl_error() throw()
    : exception(), mMessage(SDL_GetError())
  {
  }

  sdl_error::sdl_error(const std::string& msg) throw()
    : exception(), mMessage(msg)
  {
  }

  sdl_error::~sdl_error() throw()
  {
  }

  const char* sdl_error::what() const throw()
  {
      return mMessage.c_str();
  }
}