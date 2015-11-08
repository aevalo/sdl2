#ifndef SDL_RENDERER_HPP_INCLUDED
#define SDL_RENDERER_HPP_INCLUDED

#include <SDL_stdinc.h>

// Forward declarations
struct SDL_Renderer;

namespace sdl2
{
  class renderer
  {
    public:
      renderer(SDL_Renderer* renderer);
      ~renderer();

      operator SDL_Renderer*() {return mRenderer;}
    protected:
      SDL_Renderer* mRenderer;
  };
}

#endif // SDL_RENDERER_HPP_INCLUDED