#include <SDL.h>
#include "sdl_error.hpp"

namespace sdl2
{
  void Init(Uint32 flags)
  {
    if(SDL_Init(flags) < 0)
    {
      throw sdl_error();
    }
  }

  void InitSubSystem(Uint32 flags)
  {
    if(SDL_InitSubSystem(flags) < 0)
    {
      throw sdl_error();
    }
  }
  
  void Quit()
  {
    SDL_Quit();
  }
  
  void QuitSubSystem(Uint32 flags)
  {
    SDL_QuitSubSystem(flags);
  }
  
  void SetMainReady()
  {
    SDL_SetMainReady();
  }
  
  Uint32 WasInit(Uint32 flags)
  {
    return SDL_WasInit(flags);
  }
}
