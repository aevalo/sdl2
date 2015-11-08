#ifndef SDL_WINDOW_HPP_INCLUDED
#define SDL_WINDOW_HPP_INCLUDED

#include <SDL_stdinc.h>

// Forward declarations
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

namespace sdl2
{
  class renderer;
  class window
  {
    public:
      window(const char* title, int x, int y, int w, int h, Uint32 flags);
      window(const void* data);
      window(int width, int height, Uint32 flags, renderer** renderer);
      ~window();

      SDL_Renderer* renderer();

      void icon(SDL_Surface* icon);

      const char* title();
      void title(const char* title);
    protected:
      SDL_Window* mWindow;
  };
}

#endif // SDL_WINDOW_HPP_INCLUDED