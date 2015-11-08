#ifndef SDL_INIT_HPP_INCLUDED
#define SDL_INIT_HPP_INCLUDED

#include <SDL_stdinc.h>

namespace sdl2
{
  void Init(Uint32 flags);
  void InitSubSystem(Uint32 flags);
  void Quit();
  void QuitSubSystem(Uint32 flags);
  void SetMainReady();
  Uint32 WasInit(Uint32 flags);
}

#endif // SDL_INIT_HPP_INCLUDED