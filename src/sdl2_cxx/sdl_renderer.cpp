#include <SDL_render.h>
#include <SDL_log.h>
#include "sdl_renderer.hpp"

namespace sdl2
{
  renderer::renderer(SDL_Renderer* renderer)
   : mRenderer(renderer)
  {
  }
  
  renderer::~renderer()
  {
    if(mRenderer)
    {
      SDL_DestroyRenderer(mRenderer);
    }
  }
}