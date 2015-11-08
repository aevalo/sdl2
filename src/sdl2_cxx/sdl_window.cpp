#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_log.h>
#include "sdl_window.hpp"
#include "sdl_error.hpp"
#include "sdl_renderer.hpp"

namespace sdl2
{
  window::window(const char* title, int x, int y, int w, int h, Uint32 flags)
   : mWindow(NULL)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Creating window...");
    mWindow = SDL_CreateWindow(title, x, y, w, h, flags);
    if(!mWindow)
    {
      throw sdl_error();
    }
  }

  window::window(const void* data)
   : mWindow(NULL)
  {
    mWindow = SDL_CreateWindowFrom(data);
    if(!mWindow)
    {
      throw sdl_error();
    }
  }

  window::window(int width, int height, Uint32 flags, sdl2::renderer** renderer)
    : mWindow(NULL)
  {
    SDL_Renderer* sdlrenderer = NULL;
    if(SDL_CreateWindowAndRenderer(width, height, flags, &mWindow, &sdlrenderer) == -1)
    {
      throw sdl_error();
    }
    *renderer = new sdl2::renderer(sdlrenderer);
  }

  
  window::~window()
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Destroying window...");
    if(mWindow)
    {
      SDL_DestroyWindow(mWindow);
    }
  }

  SDL_Renderer* window::renderer()
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Getting renderer for window...");
    SDL_Renderer* renderer = SDL_GetRenderer(mWindow);
    if(!renderer)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Bad renderer...");
      throw sdl_error();
    }
    return renderer;
  }

  void window::icon(SDL_Surface* icon)
  {
    SDL_SetWindowIcon(mWindow, icon);
  }

  const char* window::title()
  {
    return SDL_GetWindowTitle(mWindow);
  }

  void window::title(const char* title)
  {
    SDL_SetWindowTitle(mWindow, title);
  }
}