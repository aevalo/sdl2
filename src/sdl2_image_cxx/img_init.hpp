#ifndef IMG_INIT_HPP_INCLUDED
#define IMG_INIT_HPP_INCLUDED

#include <SDL_version.h>

namespace sdl2
{
  namespace image
  {
    void LinkedVersion(SDL_version& version);
    void CompiledVersion(SDL_version& version);
    void Init(int flags);
    void Quit();
  }
}

#endif // IMG_INIT_HPP_INCLUDED